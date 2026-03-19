#include<stdio.h>

int main(){
	int i=0, j=0;
	int list;
	int a, b;
	int result;
	while(1){
		scanf("%d", &list);
		int result = list;
		if(list==0){
			break;
		}
		i++;
		while(result>9){
			int b=0;
			a = result;
			while(a>0){
			b = b+(a%10);
			a = a/10;
		}
			result = b;
		}
		printf("%d\n", result);
		
	}
	
} 
