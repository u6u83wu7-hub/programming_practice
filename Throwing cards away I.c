#include <stdio.h>
#define MAX 1000

int main() {
    int num;
    while(scanf("%d", &num) && num) {
        int carddeck[MAX];
        int discard[MAX];
        int front = 0;       /* 指向最上面牌*/
        int rear = num;      /* 指向最後牌的下一個位置*/
        int countd = 0;

        /* 初始化牌堆*/
        int i;
        for(i = 0; i < num; i++)
            carddeck[i] = i + 1;

        while(rear - front > 1) { /* 牌數 > 1*/
            discard[countd++] = carddeck[front++];    
            carddeck[rear++] = carddeck[front++];     
        }

        /* 輸出*/ 
        printf("Discarded cards:");
			if(countd > 0) {
    		printf(" ");
    		for(i = 0; i < countd; i++) {
    	    	if(i) printf(", ");
        		printf("%d", discard[i]);
    		}
			}
		printf("\n");
        printf("Remaining card: %d\n", carddeck[front]);
    }
    return 0;
}

