#include<stdio.h>

int main(){
	int num;
	int i;
	while(scanf("%d", &num)==1){
		int num_list[1000];
		for(i=0; i<num; i++){
			scanf("%d", &num_list[i]);
		}
		for(i=num-1; i>0; i--){
			printf("%d ", num_list[i]);
		}
		printf("%d", num_list[i]);
	}
}
