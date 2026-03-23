#include<stdio.h>

int main(){
	long long int num;
	while(1){
		scanf("%lld", &num);
		if(num ==0){
			break;
		}
		long long int temp = num;
		int y, i, j;
		if(temp< 10){
			printf("%lld", temp);
		}else{
			for(j=0; y>=10 || temp>=10; j++){
				y = 0;
				for(i=0; temp >0; i++){
					y+= temp %10;
					temp = temp/10;
				}
				temp = y;
			}
			printf("%d", y);
	    }
	}
}
