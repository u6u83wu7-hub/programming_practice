#include<stdio.h>
//°ÊºA³W¹ºDP 
#define Max 1000

int main(){
	int num;
	int i, j, r;
	int num_list[Max];
	while(scanf("%d", &num)==1){
		for(i=0; i<num; i++){
			scanf("%d", &num_list[i]);
		}
		int dp[Max];
		for(i=0; i<num; i++){
			dp[i]=num_list[i];
		}
		for(i=0; i<num; i++){
			for(j=0; j<i; j++){
				if(num_list[j]<num_list[i]){
					if(num_list[i]+dp[j]>dp[i]){
						dp[i]= num_list[i]+dp[j];
					}
				}
			}	
		}
		int max_num=0;
		for(i=0; i<num; i++){s8
			if(dp[i]>max_num){
				max_num = dp[i];
			}
		}
		printf("%d\n", max_num);
	} 
} 
