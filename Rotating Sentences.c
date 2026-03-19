#include<stdio.h>
#include<string.h>

// 建議設大一點，避免剛好 100 字時 fgets 讀取不完整導致換行符號殘留
#define Max_row 105 
#define Max_col 105 

int main(){
    // 將陣列初始化為 0，這是一個好習慣
    char string[Max_row][Max_col] = {0}; 
    int row_count = 0;
    int i, j, k;

    // 讀取輸入
    while(fgets(string[row_count], sizeof(string[row_count]), stdin)){
        // 移除換行符號
        string[row_count][strcspn(string[row_count], "\n")] = '\0';
        
        row_count++;
        if(row_count >= Max_row){
            break;
        }
    }

    int Max_len = 0;
    for(i = 0; i < row_count; i++){
        if(strlen(string[i]) > Max_len){
            Max_len = strlen(string[i]);
        }
    }

    // 開始旋轉輸出
    for(i = 0; i < Max_len; i++){ // i 代表原本字串的第幾個字
        for(j = row_count - 1; j >= 0; j--){ // j 代表第幾句 (從最後一句往回印)
            
            if(strlen(string[j]) > i){
                // 如果這句長度夠長，直接印出字元
                printf("%c", string[j][i]);
            }
            else{
                // [關鍵修正]：判斷是否需要印空白
                // 只有當 "更右邊 (原本輸入的上方句子)" 還有內容時，才需要補空白來對齊
                // 如果右邊已經沒東西了，這個空白就是多餘的 (Trailing Space)，不能印
                
                int has_char_right = 0;
                for(k = j - 1; k >= 0; k--){
                    if(strlen(string[k]) > i){
                        has_char_right = 1;
                        break;
                    }
                }
                
                if(has_char_right){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
