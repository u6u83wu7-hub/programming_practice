#include<stdio.h>
#include<string.h>
#define MAX 1001 
//ASCII大寫65-90，小寫97-122 

int main(){
	char line1[MAX];
	char line2[MAX];
	int alphabet[26]={0};	// 記錄 line1 各字母出現次數
	int same_alp[26]={0};	// 記錄共同字母的最小出現次數
	int i,j;
	while(fgets(line1, sizeof(line1), stdin)){
		memset(alphabet, 0, sizeof(alphabet));
		memset(same_alp, 0, sizeof(same_alp));
		
		
		for(i =0; line1[i] != '\0'; i++){
			if(line1[i] >= 'a' && line1[i] <= 'z'){
        	alphabet[line1[i] - 'a'] += 1;
    		}
		}
		
		fgets(line2, sizeof(line2), stdin);
		for (i = 0; line2[i] != '\0'; i++) {
            if (line2[i] >= 'a' && line2[i] <= 'z') {
                int idx = line2[i] - 'a';
                if (alphabet[idx] > 0) {
                    same_alp[idx]++;      // 第二行也有 → 計次
                    alphabet[idx]--;      // 減掉一個，確保不重複多算
                }
            }
        }
        
        
		for(i=0; i<26; i++){
			if(same_alp[i]!=0){
				for(j=0; j<same_alp[i]; j++){
					printf("%c", 'a' + i);	
				}
			}
		}
		printf("\n");
	}
}
