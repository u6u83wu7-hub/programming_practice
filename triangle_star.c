#include<stdio.h>

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j;
		int num =n*2-1;
		for(i=1; i<n+1; i++){
			for(j=0/*起*/; j<n-i/*終*/; j++){//用<的話就會剛好跑終點-起點次數 
				printf(" ");
			}
			for(j=0; j<(2*i-1); j++){
				printf("*");
			}

			printf("\n");
		}
	}
} 
