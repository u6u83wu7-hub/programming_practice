#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool is_prime(int n){
	long s_n=(long)sqrt(n);
	long i;
	for(i=2; i<=s_n; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int turn(int n){
	int n2=0;
	int temp;
	while(n>0){
		temp = n%10;
		n2 = n2*10+temp;
		n = n/10;
	}
	return n2;
}

int main(){
	long num;
	while(scanf("%d", &num)==1){
		long flag=0;
		if(num<=1){
			flag =0;
		}else if(is_prime(num)){
			flag = 1;
			long num2=turn(num);
			if(is_prime(num2)&&num2!=num){
				flag =2;
			}
		}
		if(flag ==0){
			printf("%d is not prime.\n", num);
		}else if(flag==1){
			printf("%d is prime.\n", num);
		}else{
			printf("%d is emirp.\n", num);
		}
	}
	return 0;
} 
