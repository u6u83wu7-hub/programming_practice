#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEGREE 100
#define RESULT_MAX_DEGREE (MAX_DEGREE * 2)

// 解析多項式字串
void parse_polynomial(char* poly_str, int* coeffs) {
    char* p = poly_str;
    while (*p) {
        long coeff;
        int sign = 1;
        if (*p == '-') {
            sign = -1;
            p++;
        } else if (*p == '+') {
            p++;
        }

        if (isdigit(*p)) {
            coeff = strtol(p, &p, 10);
        } else {
            coeff = 1;
        }
        coeff *= sign;

        int degree = 0;
        if (*p == 'x') {
            p++;
            if (*p == '^') {
                p++;
                degree = strtol(p, &p, 10);
            } else {
                degree = 1;
            }
        }
        if (degree <= MAX_DEGREE) {
            coeffs[degree] += coeff;
        }
    }
}

// 印出多項式
void print_polynomial(int* coeffs, int max_degree_to_print) {
    int first_term = 1;
    int i; 
    for (i= max_degree_to_print; i >= 0; i--) {
        if (coeffs[i] != 0) {
            if (!first_term && coeffs[i] > 0) printf("+");
            if (i == 0) {
                printf("%d", coeffs[i]);
            } else if (i == 1) {
                if (coeffs[i] == 1) printf("x");
                else if (coeffs[i] == -1) printf("-x");
                else printf("%dx", coeffs[i]);
            } else {
                if (coeffs[i] == 1) printf("x^%d", i);
                else if (coeffs[i] == -1) printf("-x^%d", i);
                else printf("%dx^%d", coeffs[i], i);
            }
            first_term = 0;
        }
    }
    if (first_term) printf("0");
    printf("\n");
}

int main() {
    char operation[20];
    char poly1_str[1024], poly2_str[1024];
    int poly1_coeffs[MAX_DEGREE + 1] = {0};
    int poly2_coeffs[MAX_DEGREE + 1] = {0};

    // 輸入操作
    printf("Enter operation (add, subtract, multiply): ");
    scanf("%s", operation);

    // 輸入多項式
    printf("Enter first polynomial: ");
    scanf(" %[^\n]", poly1_str);  // 讀整行
    printf("Enter second polynomial: ");
    scanf(" %[^\n]", poly2_str);

    parse_polynomial(poly1_str, poly1_coeffs);
    parse_polynomial(poly2_str, poly2_coeffs);
	int i,j; 
    if (strcmp(operation, "add") == 0) {
        int result[MAX_DEGREE + 1] = {0};
        
        for (i= 0; i <= MAX_DEGREE; i++)
            result[i] = poly1_coeffs[i] + poly2_coeffs[i];
        print_polynomial(result, MAX_DEGREE);
    } 
    else if (strcmp(operation, "subtract") == 0) {
        int result[MAX_DEGREE + 1] = {0};
        for (i = 0; i <= MAX_DEGREE; i++)
            result[i] = poly1_coeffs[i] - poly2_coeffs[i];
        print_polynomial(result, MAX_DEGREE);
    } 
    else if (strcmp(operation, "multiply") == 0) {
        int result[RESULT_MAX_DEGREE + 1] = {0};
        for (i = 0; i <= MAX_DEGREE; i++) {
            if (poly1_coeffs[i] == 0) continue;
            for (j = 0; j <= MAX_DEGREE; j++) {
                if (poly2_coeffs[j] == 0) continue;
                result[i + j] += poly1_coeffs[i] * poly2_coeffs[j];
            }
        }
        print_polynomial(result, RESULT_MAX_DEGREE);
    } 
    else {
        printf("Error: Unknown operation '%s'. Use add, subtract, or multiply.\n", operation);
        return 1;
    }

    return 0;
}

