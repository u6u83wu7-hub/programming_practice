#include<stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct{
	char letter;
	int count;
}LetterCount;

int sorting(const void *a, const void *b){
	const LetterCount *lc1 = (const LetterCount *)a;
    const LetterCount *lc2 = (const LetterCount *)b;
    
    if(lc1->count < lc2->count){ // Use -> for pointers
    return 1;
	}
	if(lc1->count > lc2->count){ // Use -> for pointers
    return -1;
	}
		// 如果 lc1 的次數較大，它應該排在前面，所以回傳負數，qsort 不交換
	else{
		return lc1->count - lc2->count;	
	} 
}

int main(){
	int num;
	int i, j=0;
	scanf("%d", &num);
	getchar();
	char list[MAX];
	int count [26]={0};
	LetterCount LC[26];
	for(i =0; i<num; i++){
		fgets(list, sizeof(list), stdin);
		for(j=0;list[j]!='\0'; j++){
			if(isalpha(list[j])){
				count[toupper(list[j]) - 65]++;
			}
		}
	}
	int count2=0;
	for(i=0; i<26; i++){
		if(count[i]>0){
			LC[count2].letter = 65+i;
			LC[count2].count = count[i];
			count2++;
		}
	}
	 qsort(LC, count2, sizeof(LetterCount), sorting);
	
	for(i =0; i<count2; i++){
		printf("%c %d\n", LC[i].letter, LC[i].count);
	}
	
} 
