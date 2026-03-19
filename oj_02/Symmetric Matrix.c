#include <stdio.h>
#define MAX 100

int main() {
    long int matrix[MAX][MAX];
    int T;
    int count , i, j;
    scanf("%d", &T);
	getchar(); //§ì±¼´«¦æ 
    for (count = 1; count <= T; count++) {
        int n;
        char tmp1, tmp2;
        scanf(" N = %d", &n); // Åª N = n

        // Åª¯x°}
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%ld", &matrix[i][j]);
            }
        }

 
        int symmetric = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] < 0 || matrix[i][j] != matrix[n - 1 - i][n - 1 - j]) {
                    symmetric = 0;
                    break;
                }
            }
            if (!symmetric) break; 
        }


        if (symmetric) {
            printf("Test #%d: Symmetric.\n", count);
        } else {
            printf("Test #%d: Non-symmetric.\n", count);
        }
    }

    return 0;
}

