/*Primary Arithmetic（進位次數）
題目說明： 
給你兩個非負整數，請計算它們相加時會產生幾次「進位」。
範例： 
輸入：

123 456
555 555
123 594
0 0
輸出：

No carry operation.
3 carry operations.
1 carry operation.*/

#include <stdio.h>
#include <string.h>

int main(){
    char a[1000], b[1000];

    while(scanf("%s %s", a, b) == 2){
    	if(a==0&&b==0){
    		break;
		}

        if(strcmp(a,"0")==0 && strcmp(b,"0")==0)
            break;

        int len_a = strlen(a);
        int len_b = strlen(b);

        int i = len_a - 1;
        int j = len_b - 1;

        int carry = 0;
        int c = 0;   

        while(i >= 0 || j >= 0){

            int digit_a = 0;
            int digit_b = 0;

            if(i >= 0)
                digit_a = a[i] - '0';

            if(j >= 0)
                digit_b = b[j] - '0';

            if(digit_a + digit_b + c >= 10){
                c = 1;
                carry++;
            }
            else{
                c = 0;
            }

            i--;
            j--;
        }

        if(carry == 0)
            printf("No carry operation.\n");
        else if(carry == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", carry);
    }
}
