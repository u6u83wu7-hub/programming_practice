/*有n個整數的序列我們稱為jolly jumper，如果相鄰的2個數其差的絕對值恰好為1到n-1。例如：
1 4 2 3
就是jolly jumper（n=4）。因為相鄰2數的差的絕對值為3,2,1，就是1到n-1。但是
1 4 2 -1 6 
不是jolly jumper（n=5）。因為相鄰2數的差的絕對值為3,2,3,7，並非1到n-1。
你的任務是寫一個程式來判斷一個整數序列是否為jolly jumper。*/ 
#include<stdio.h>
#include<stdlib.h>
 
int main(){
	int amount=0;
	int string[3000];
	int i=0;
	int a;
	while(scanf("%d", &amount) == 1){
		int check[3000] = {0};
		for(i=0; i<amount; i++){
			scanf("%d", &string[i]);
		}
		for(int i = 0; i < amount - 1; i++){
            int sub = abs(string[i+1] - string[i]);
            if(sub >= 1 && sub <= amount - 1){
                check[sub] = 1; 
            }
        }
		int flag=1;
		for(i=1; i<=amount-1; i++){
			if(check[i]!=1){
				printf("Not jolly\n");
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("Jolly\n");
		}
		
	}
}
