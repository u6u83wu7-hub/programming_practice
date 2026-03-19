#include<stdio.h>
#define MAX 100

int main(){
	int num =0;
	int i, j, d;
	scanf("%d", &num);
	for(i = 0; i<num ; i++){
		int party_num = 0;
		int day_num = 0;
		int hartals = 0;
		int temp_har = 0;
		scanf("%d", &day_num);
		scanf("%d", &party_num);
		int h[MAX];
		for(j = 0; j<party_num; j++){
			scanf("%d", &h[j]);
		}
		for(d = 1; d<=day_num; d++){
			if((d-6)%7==0||(d%7)==0){
				continue;
			}
			else{
				for(j = 0; j<party_num; j++){
					if(d%h[j]==0){
						temp_har = 1;
					}
				}
				if (temp_har==1){
					hartals+=1;
					temp_har=0;
				}
			}
			
		}
		printf("%d\n", hartals);
	}
}
