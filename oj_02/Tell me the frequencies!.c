#include<stdio.h> 
#include <stdlib.h> 
#include <string.h> // 需要 memset
#define MAX_ASC 129
#define MAX 1002

typedef struct{
	int Asc;
	int count;	
}Char_Freq;	

int sorting(const void * a, const void * b){
	 Char_Freq *ca =(Char_Freq*)a;
	 Char_Freq *cb =(Char_Freq*)b;
	if(ca->count !=cb->count){
		return ca->count -cb->count; 
	}
	else{
		return -(ca->Asc-cb->Asc);
	}
	}


int main(){
	char string[MAX];
	Char_Freq Ascii[MAX_ASC];
	int i, a, j=0;
	//fgets() 在成功讀到一行字時，會回傳「那個字串的指標」（非空）。
    //當讀到 EOF 或發生錯誤時，會回傳 NULL。
	while(fgets(string, sizeof(string), stdin)!= NULL){
		memset(Ascii, 0, sizeof(Ascii));
		//memset:用於將整個區域中所有字節設定為特定值 
		for(i=0;string[i] != '\0';i++){
			if(string[i] != '\n' && string[i] != '\r'){
				a=(unsigned char)string[i];
				Ascii[a].Asc =a;
				Ascii[a].count+=1;	
			}
		}
		// 把非 0 count 的項目挑出來
		//qsort不能比較一堆0的會壞掉(超廢)所以要挑出來... 
        Char_Freq valid[MAX_ASC];
        int count2 = 0;
        for (i = 0; i < MAX_ASC; i++) {
            if (Ascii[i].count > 0) {
                valid[count2++] = Ascii[i];
            }
        }

        // 排序有效資料
        qsort(valid, count2, sizeof(Char_Freq), sorting);

        // 輸出結果
        for (i = 0; i < count2; i++) {
            printf("%d %d\n", valid[i].Asc, valid[i].count);
        }
		printf("\n");
		j+=1;
	}
}
