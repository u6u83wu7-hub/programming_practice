// infix_converter_interactive.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXTOK 1024
#define MAXLEN 4096

typedef struct {
    char s[64];
} Token;

int isOperatorChar(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int prec(const char *op) {
    if (strcmp(op, "u")==0) return 4;
    if (strcmp(op, "^")==0) return 3;
    if (strcmp(op, "*")==0 || strcmp(op, "/")==0) return 2;
    if (strcmp(op, "+")==0 || strcmp(op, "-")==0) return 1;
    return 0;
}
int isRightAssoc(const char *op) {
    return strcmp(op, "^")==0 || strcmp(op, "u")==0;
}

int tokenize(const char *in, Token tokens[]) {
    int i=0, n=0;
    while (in[i]) {
        if (isspace((unsigned char)in[i])) { i++; continue; }
        if (isdigit((unsigned char)in[i])) {
            int j=0; char buf[64]; buf[0]=0;
            while (isdigit((unsigned char)in[i]) || in[i]=='.') {
                if (j < 60) buf[j++]=in[i];
                i++;
            }
            buf[j]=0;
            strcpy(tokens[n++].s, buf);
        } else if (isalpha((unsigned char)in[i])) {
            char tmp[4] = {in[i],0,0,0};
            strcpy(tokens[n++].s, tmp);
            i++;
        } else if (isOperatorChar(in[i])) {
            char tmp[4] = {in[i],0,0,0};
            strcpy(tokens[n++].s, tmp);
            i++;
        } else if (in[i]=='(' || in[i]==')') {
            char tmp[4] = {in[i],0,0,0};
            strcpy(tokens[n++].s, tmp);
            i++;
        } else {
            i++; // 忽略非法字元
        }
    }
    return n;
}

void infixToPostfixTokens(Token tokens[], int tcount, char *postfix_out) {
    const int MAXS = 1024;
    char opstack[MAXS][16];
    int optop=-1;
    postfix_out[0]=0;
    int prevOperand=0;
    int i;
    for (i=0;i<tcount;i++) {
        char *tk = tokens[i].s;
        if (isdigit((unsigned char)tk[0]) || isalpha((unsigned char)tk[0])) {
            strcat(postfix_out, tk);
            strcat(postfix_out, " ");
            prevOperand=1;
            continue;
        }
        if (strcmp(tk, "(")==0) { optop++; strcpy(opstack[optop], tk); prevOperand=0; continue; }
        if (strcmp(tk, ")")==0) {
            while (optop>=0 && strcmp(opstack[optop],"(")!=0) { strcat(postfix_out, opstack[optop]); strcat(postfix_out," "); optop--; }
            if (optop>=0 && strcmp(opstack[optop],"(")==0) optop--;
            prevOperand=1; continue;
        }
        if (isOperatorChar(tk[0])) {
            if (strcmp(tk,"-")==0 && !prevOperand) strcpy(tk,"u");
            while (optop>=0 && strcmp(opstack[optop],"(")!=0) {
                char *topop=opstack[optop];
                int ptop=prec(topop), pcurr=prec(tk);
                if ((!isRightAssoc(tk) && ptop>=pcurr) || (isRightAssoc(tk) && ptop>pcurr)) {
                    strcat(postfix_out, opstack[optop]); strcat(postfix_out," "); optop--;
                } else break;
            }
            optop++; strcpy(opstack[optop], tk);
            prevOperand=0;
            continue;
        }
    }
    while (optop>=0) { strcat(postfix_out, opstack[optop]); strcat(postfix_out," "); optop--; }
    int len=strlen(postfix_out); if (len>0 && postfix_out[len-1]==' ') postfix_out[len-1]=0;
}

void reverseTokens(Token t[], int n) {
	int i;
    for (i=0;i<n/2;i++) { Token tmp=t[i]; t[i]=t[n-1-i]; t[n-1-i]=tmp; }
    for (i=0;i<n;i++) {
        if (strcmp(t[i].s,"(")==0) strcpy(t[i].s,")");
        else if (strcmp(t[i].s,")")==0) strcpy(t[i].s,"(");
    }
}

void infixToPrefixTokens(Token tokens[], int tcount, char *prefix_out) {
    Token tmp[MAXTOK];
    int i;
    for (i=0;i<tcount;i++) tmp[i]=tokens[i];
    reverseTokens(tmp, tcount);
    char post[MAXLEN]; post[0]=0;
    infixToPostfixTokens(tmp,tcount,post);

    Token postTokens[MAXTOK]; int pc=0;
    char buf[MAXLEN]; strcpy(buf, post);
    char *p=strtok(buf," ");
    while (p) { strcpy(postTokens[pc++].s,p); p=strtok(NULL," "); }
    char out[MAXLEN]; out[0]=0;
    for (i=pc-1;i>=0;i--) { strcat(out, postTokens[i].s); if (i>0) strcat(out," "); }
    strcpy(prefix_out,out);
}

double evalPostfixTokens(const char *postfix,
                         char vars[][16], double vals[], int varCount)
{
    double stack[MAXLEN]; int sp = 0;
    char tmp[MAXLEN]; strncpy(tmp, postfix, MAXLEN-1); tmp[MAXLEN-1]=0;
    char *tok = strtok(tmp, " ");
    while (tok) {
        int isNum = 1, ti = 0, k;
        if (tok[0] == '-' && strlen(tok) > 1) ti = 1;
        for (; tok[ti]; ti++) if (!isdigit((unsigned char)tok[ti]) && tok[ti] != '.') isNum=0;
        if (isNum) { stack[sp++] = atof(tok); tok=strtok(NULL," "); continue; }
        if (strcmp(tok, "u")==0) { double a=stack[--sp]; stack[sp++]=-a; tok=strtok(NULL," "); continue; }
        if (isalpha((unsigned char)tok[0]) && strlen(tok)==1) {
            char v=tok[0]; double val=0.0; for (k=0;k<varCount;k++) if(vars[k][0]==v){ val=vals[k]; break; }
            stack[sp++]=val; tok=strtok(NULL," "); continue;
        }
        if (strcmp(tok, "+")==0 || strcmp(tok,"-")==0 || strcmp(tok,"*")==0 || strcmp(tok,"/")==0 || strcmp(tok,"^")==0) {
            double b=stack[--sp], a=stack[--sp], r=0.0;
            if (strcmp(tok,"+")==0) r=a+b;
            else if(strcmp(tok,"-")==0) r=a-b;
            else if(strcmp(tok,"*")==0) r=a*b;
            else if(strcmp(tok,"/")==0) r=a/b;
            else if(strcmp(tok,"^")==0) r=pow(a,b);
            stack[sp++]=r; tok=strtok(NULL," "); continue;
        }
        tok=strtok(NULL," ");
    }
    return sp>0 ? stack[sp-1]:0.0;
}

int main() {
    char infixRaw[MAXLEN];
    printf("Enter infix expression: ");
    fgets(infixRaw, MAXLEN, stdin);
    infixRaw[strcspn(infixRaw, "\n")] = 0; // 去掉換行

    int varCount=0;
    char vars[64][16]; double vals[64];

    printf("Enter number of variables: ");
    int nvars; scanf("%d", &nvars); getchar();
    int i;
    for(i=0;i<nvars;i++){
        char name[16]; double val;
        printf("Variable %d name (single letter): ", i+1); scanf("%s", name);
        printf("Variable %d value: ", i+1); scanf("%lf", &val); getchar();
        strncpy(vars[varCount], name, 15); vars[varCount][15]=0;
        vals[varCount]=val; varCount++;
    }

    Token tokens[MAXTOK]; int tcount=tokenize(infixRaw, tokens);
    char postfix[MAXLEN], prefix[MAXLEN];
    infixToPostfixTokens(tokens,tcount,postfix);
    infixToPrefixTokens(tokens,tcount,prefix);

    double result=evalPostfixTokens(postfix, vars, vals, varCount);

    char pfconcat_display[MAXLEN]="", preconcat_display[MAXLEN]="", postfix_tokens_display[MAXLEN]="";
    char tkbuf[MAXLEN]; char *p;

    strcpy(tkbuf, prefix); p=strtok(tkbuf," ");
    while(p){ if(strcmp(p,"u")==0) strcat(preconcat_display,"-"); else strcat(preconcat_display,p); p=strtok(NULL," "); }

    strcpy(tkbuf, postfix); p=strtok(tkbuf," ");
    while(p){ if(strcmp(p,"u")==0) strcat(pfconcat_display,"-"); else strcat(pfconcat_display,p); p=strtok(NULL," "); }

    strcpy(tkbuf, postfix); p=strtok(tkbuf," ");
    while(p){ if(strcmp(p,"u")==0) strcat(postfix_tokens_display,"-"); else strcat(postfix_tokens_display,p); p=strtok(NULL," "); if(p) strcat(postfix_tokens_display," "); }

    printf("Prefix: %s\n", preconcat_display);
    printf("Postfix: %s\n", pfconcat_display);
    printf("Postfix(tokens): %s\n", postfix_tokens_display);
    printf("Result: %.2f\n", result);

    return 0;
}

