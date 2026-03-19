#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct equNode *equPointer;
typedef struct equNode {
    int coef;
    char variable;
    int expon;
    equPointer link;
} equNode;

typedef struct equHead *headPointer;
typedef struct equHead {
    int nodeNumber;
    char equNotation;
    equPointer link;
    headPointer hlink;
} equHead;

headPointer equList = NULL;

headPointer findEquation(char name) {
    headPointer p = equList;
    while (p) {
        if (p->equNotation == name) return p;
        p = p->hlink;
    }
    return NULL;
}

void freeNodes(equPointer p) {
    while (p) {
        equPointer t = p->link;
        free(p);
        p = t;
    }
}

void deleteEquation(char name) {
    headPointer *p = &equList;
    while (*p) {
        if ((*p)->equNotation == name) {
            headPointer temp = *p;
            *p = (*p)->hlink;
            freeNodes(temp->link);
            free(temp);
            return;
        }
        p = &((*p)->hlink);
    }
}

void insertEquation(char name, equPointer terms, int count) {
    headPointer newEq = malloc(sizeof(equHead));
    newEq->nodeNumber = count;
    newEq->equNotation = name;
    newEq->link = terms;
    newEq->hlink = equList;
    equList = newEq;
}

void printEquationToBuffer(char *buffer, char name, equPointer terms, int count) {
    char tmp[256];
    sprintf(buffer + strlen(buffer), "%c %d\n", name, count);
    equPointer t;
    for (t = terms; t; t = t->link) {
        if (t->variable)
            sprintf(tmp, "%d %d %c\n", t->coef, t->expon, t->variable);
        else
            sprintf(tmp, "%d 0\n", t->coef);
        strcat(buffer, tmp);
    }
}

equPointer parseEquation(const char *s, bool *orderErr, int *count) {
    const char *p = s;
    equPointer head = NULL, tail = NULL;
    *count = 0;
    *orderErr = false;
    int prevExp = 9999999;

    while (*p) {
        int sign = 1;
        if (*p == '+') p++;
        else if (*p == '-') { sign = -1; p++; }

        int coef = 0;
        bool hasCoef = false;
        while (isdigit((unsigned char)*p)) {
            coef = coef * 10 + (*p - '0');
            hasCoef = true;
            p++;
        }
        if (!hasCoef) coef = 1;
        coef *= sign;

        char var = 0;
        int exp = 0;
        if (isalpha((unsigned char)*p)) {
            var = *p++;
            if (*p == '^') {
                p++;
                while (isdigit((unsigned char)*p)) {
                    exp = exp * 10 + (*p - '0');
                    p++;
                }
            } else exp = 1;
        } else exp = 0;

        if (coef == 0) { freeNodes(head); return NULL; }
        if (exp >= prevExp) { *orderErr = true; freeNodes(head); return NULL; }
        prevExp = exp;

        equPointer node = malloc(sizeof(equNode));
        node->coef = coef;
        node->variable = var;
        node->expon = exp;
        node->link = NULL;

        if (!head) head = node;
        else tail->link = node;
        tail = node;
        (*count)++;
    }
    return head;
}

int main() {
    char line[256];
    char outputs[1000][512];
    int outCount = 0;

    while (1) {
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\r\n")] = 0;

        if (strcmp(line, "0") == 0)
            break;

        char buf[512] = "";
        bool error = false;

        if (!isalpha((unsigned char)line[0])) {
            strcpy(buf, "ERROR\n");
            error = true;
        }

        char name = line[0];
        char *eq = strchr(line, '=');
        if (!eq) {
            strcpy(buf, "ERROR\n");
            error = true;
        }

        if (!error) {
            eq++;
            bool orderErr = false;
            int cnt = 0;
            equPointer terms = parseEquation(eq, &orderErr, &cnt);

            if (!terms || orderErr) {
                strcpy(buf, "ERROR\n");
                error = true;
            } else {
                // ?? 若重複名稱 → 覆蓋舊的
                if (findEquation(name))
                    deleteEquation(name);
                insertEquation(name, terms, cnt);
                printEquationToBuffer(buf, name, terms, cnt);
            }
        }

        strcpy(outputs[outCount++], buf);
    }

    // ?? 統一輸出所有結果
    int i;
    for (i = 0; i < outCount; i++)
        printf("%s", outputs[i]);
    printf("quit\n");

    return 0;
}

