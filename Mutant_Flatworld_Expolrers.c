#include<stdio.h> 
#include<string.h>
#define MAX 100

enum dir{
    N=0,
    E=1,
    S=2,
    W=3
};

int main() {
    int row, col;
    int coor[MAX+1][MAX+1];
    int robotx, roboty;
    char rdir;
    char s[MAX];
    int count;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    scanf("%d %d", &col, &row);
    int i, j;

    for (j = 0; j <= row; j++)
        for (i = 0; i <= col; i++)
            coor[j][i] = 0;

    while (scanf("%d %d %c", &robotx, &roboty, &rdir) == 3) {

        int dir;
        switch (rdir) {
            case 'N': dir = N; break;
            case 'E': dir = E; break;
            case 'S': dir = S; break;
            case 'W': dir = W; break;
        }

        scanf("%s", s);
        int lost = 0;

        int nx, ny;

        for (count = 0; s[count] != '\0'; count++) {

            if (s[count] == 'F') {
                nx = robotx + dx[dir];
                ny = roboty + dy[dir];
            }
            else if (s[count] == 'L') {
                dir = (dir + 3) % 4;
                continue;
            }
            else if (s[count] == 'R') {
                dir = (dir + 1) % 4;
                continue;
            }

            /* 處理前進可能掉落 (UVA上傳不能用//)*/
            if (nx < 0 || nx > col || ny < 0 || ny > row) {
                if (coor[roboty][robotx] == 0) {
                    coor[roboty][robotx] = 2;
                    lost = 1;
                    break;
                }
                continue; /*有 scent → 忽略 F*/
            }

            robotx = nx;
            roboty = ny;
        }

        char dirs = {'N', 'E', 'S', 'W'};
        char outdir = dirs[dir];
        printf("%d %d %c", robotx, roboty, outdir);
        if (lost) printf(" LOST");
        printf("\n");
    }

    return 0;
}

