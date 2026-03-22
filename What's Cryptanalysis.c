#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000

typedef struct{
	char ch;
	int count;
} Alphabet;
int compare(const void *a, const void *b){
	Alphabet *a1 = (Alphabet *)a;
	Alphabet *b1 = (Alphabet *)b;
	 if (b1->count != a1->count)
        return b1->count - a1->count;
    return a1->ch - b1->ch;
}

int main(){
	int n;
	int i, j;
	scanf("%d", &n);
	getchar();
	Alphabet letters[26];
	int arr[26]={0};
	for(i=0; i<n; i++){
		char word[MAX];
		int length=0;
		fgets(word, MAX, stdin);
		for(j = 0;word[j]!='\0'; j++){
			if(isalpha(word[j])){
				char c = toupper(word[j]);
				arr[c - 'A']+=1;
			}
		}
	}
	int k=0;
		for(i=0; i<26; i++){
			if(arr[i]!=0){
				letters[k].ch = i+'A';
				letters[k].count = arr[i];
				k+=1;
			}
		}
		qsort(letters, k, sizeof(Alphabet), compare);
	for(i=0; i<k; i++){
		printf("%c %d\n", letters[i].ch, letters[i].count);
	} 
	
} 
