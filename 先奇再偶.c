#include<stdio.h>
#define Max 1000
int num;

void bubble(int list[Max], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=1; j<n -i; j++){
			int temp;
			if(list[j-1]>list[j]){
				temp =list[j-1];
				list[j-1]=list[j];
				list[j]= temp;
			}
		}
	}
}
int main(){
	while(scanf("%d", &num)==1){
		int odd[Max];
		int even[Max];
		int temp, o=0, e=0;
		int i, j;
		for(i=0; i<num; i++){
			scanf("%d", &temp);
			if(temp%2==1){
				odd[o] = temp;
				o++;
			}else{
				even[e] = temp;
				e++;
			}
		}
		bubble(odd, o);
		bubble(even, e);
		if(e==0){
			for(i=o-1; i>0; i--){
				printf("%d ", odd[i]); 
			}
			printf("%d", odd[i]);
		}else{
			for(i=o-1; i>=0; i--){
				printf("%d ", odd[i]); 
			}
			for(i=0; i<e-1; i++){
				printf("%d ", even[i]); 
			}
			printf("%d", even[i]);
		}
		printf("\n");
	}
}
