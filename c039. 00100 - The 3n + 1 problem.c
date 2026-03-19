#include <stdio.h>

int main() {
    int i, j, n;
    while (scanf("%d %d", &i, &j) == 2) {
        int a = i, b = j;
        if (a > b) {
            int t = a; a = b; b = t;
        }

        int max_cycle = 0;
        for (n = a; n <= b; ++n) {
            unsigned long long x = n;   // 使用較大型別以避免溢位
            int cycle = 1;              // 包含起始數本身
            while (x != 1) {
                if (x % 2 == 1) x = 3 * x + 1;
                else x = x / 2;
                ++cycle;
            }
            if (cycle > max_cycle) max_cycle = cycle;
        }

        printf("%d %d %d\n", i, j, max_cycle);
    }
    return 0;
}
