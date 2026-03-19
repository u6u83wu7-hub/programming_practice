#include<stdio.h>
#include <stdlib.h>
#define MAX 500

int cmp(const void*a, const void*b)
//void* → 代表「泛型指標」，讓 qsort() 可以排序任何型別
//const → 確保比較函式不會修改元素內容
{
	return (*(int*)a -*(int*)b);// 把 a 轉成 int* 再取值
	// (int*) 把 void* 強制轉型成 int*
}

int main()
{
	int n;
	int rooms[MAX];
	int i, j;
	int middle;
	int t;
	scanf("%d", &t);
	for(j =0; j<t; j++){
	scanf("%d", &n);
	int sum=0;
	for(i=0; i<n; i++)
	{
		scanf("%d", &rooms[i]);
	}
	qsort(rooms, n, sizeof(int), cmp);  
	// 陣列起始位置, 元素個數, 每個元素的大小（用 sizeof）, 比較函式(要自己寫怎樣是大) 
	if (n % 2 != 0) {
    middle = rooms[n / 2];        // 奇數 → 正中間
	} else {
    middle = rooms[(n / 2) - 1];  // 偶數 → 左中位數（取右邊也可以）
	}
	for(i=0; i<n; i++)
	{
		sum+=abs(rooms[i]-middle);
	}
	printf("%d\n", sum);	
		
	}

}
