#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int M_global;

int remainder_comp(const void*a, const void*b){
	const int x = *(const int *)a;
	const int y = *(const int *)b;
	
	if ( (x % M_global) != (y % M_global) ) {
    return (x % M_global) - (y % M_global);
	}
	int is_odd1 = abs(x) % 2;
    int is_odd2 = abs(y) % 2;
	if((y%M_global)==(x%M_global)){
		if (is_odd1 != is_odd2) {
        return is_odd2 - is_odd1;
		 // is_odd1=1(), is_odd2=0(案) -> 0-1=-1, num1 逼玡
    }

    // 砏玥 2.2: 常琌计计纔 (患搭逼)
    if (is_odd1) { 
	// ㄢ常琌计
        return y - x; 
		// num1>num2 -> 璽 -> num1 逼玡
    } 
    // 砏玥 2.3: 常琌案计计纔 (患糤逼)
    else { 
	// ㄢ常琌案计
        return x - y; 
		// num1<num2 -> 璽 -> num1 逼玡
    }
	}
}

int main(){
	int n, i, j;
	int list[MAX];
	
	while(1){
		scanf("%d %d", &n, &M_global);
		if(n==0&&M_global==0){
			break;
		}
		printf("%d %d\n", n, M_global);
		for(i=0; i<n; i++){
			scanf("%d", &list[i]);
		}
	
		qsort(list, n, sizeof(int), remainder_comp);
	
		for(i=0; i<n; i++){
			printf("%d\n", list[i]);
		}
		}
	printf("0 0\n");
}
