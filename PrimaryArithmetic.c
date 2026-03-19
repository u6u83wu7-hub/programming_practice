#include<stdio.h>

int main(){
	int num1, num2=0;
	while(1){
		scanf("%d %d", &num1, &num2);
		if(num1 == 0&& num2 ==0){
			break;
		}
		if(num1<num2){
			int temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int temp1 = num1;
		int temp2 = num2;
		int n1 = 0;
		int n2 = 0;
		int sum=0;
		int carry =0;
		while(temp1>0){
			n1 = temp1%10;
			n2 = temp2%10;
			if((n1+n2+carry)>=10){
				carry = 1;
				sum+=1;
			}else{
				carry = 0;
			}
			temp1 = (temp1 - n1)/10;
			temp2 = (temp2 - n2)/10;
		}
		if(sum ==0){
			printf("No carry operation.");
		}else if(sum==1){
			printf("1 carry operation.");
		}else{
			printf("%d carry operations.", sum);
		}
			
	}


} 
