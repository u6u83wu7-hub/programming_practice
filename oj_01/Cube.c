#include<stdio.h>
#define MAX 1000 

typedef struct item{
	int front;
	int back;
	int height;
	int now_x;	// 這個面(0-5)的索引
	int now_y;	// 這個積木(0 to num-1)的索引
	int prev_x;	// 塔中底下那個積木的面索引
	int prev_y;	// 塔中底下那個積木的索引
} items;

int main(){
	int i, j, r, k;
	int count =1;
	while(1){
		int num;//有幾個cube 
		items coordinate[MAX][6];	//第幾個CUBE，第幾面 (y, x)
		int color_a;
		int color_b;
		scanf("%d", &num);
		if(num ==0){
			break;
		}
		//將輸入變成一張大表格 
		for(i=0; i<num;i++){
		int c[6];
			scanf("%d %d %d %d %d %d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5]);
			coordinate[i][0].front = c[0]; coordinate[i][0].back = c[1];
			coordinate[i][1].front = c[1]; coordinate[i][1].back = c[0];
			coordinate[i][2].front = c[2]; coordinate[i][2].back = c[3];
			coordinate[i][3].front = c[3]; coordinate[i][3].back = c[2];
			coordinate[i][4].front = c[4]; coordinate[i][4].back = c[5];
			coordinate[i][5].front = c[5]; coordinate[i][5].back = c[4];
		}

		int max_height=1;
		items final_max;	//The highest hieght
		final_max.height =1;
		items max_num[MAX+1];	//放每個數最高層 
		
		for(i = 0; i < (MAX+1); i++) {
            max_num[i].height = 0;
            max_num[i].now_x = -1; 	// 用 -1 代表此顏色上還沒有積木
            max_num[i].now_y = -1;
        }
        
        final_max.now_y = -1; // 代表還沒找到任何塔	
        
        
        
		for(i =(num-1); i>=0; i--){
			int temp_maxnum[6]={0};//用以防止跟自己同一塊的疊在一起 
			int temp_prev_x[6];
			int temp_prev_y[6];
			for(j=0; j<6; j++){
				temp_maxnum[j] = max_num[coordinate[i][j].back].height + 1;
    			temp_prev_x[j] = max_num[coordinate[i][j].back].now_x;
    			temp_prev_y[j] = max_num[coordinate[i][j].back].now_y;	
					
		/*for(i = num - 1; i >= 0; i--){	//從最重的開始 
			for(j = 0; j < 6; j++){
				if(i==num - 1){
					max_num[coordinate[i][j].front].height = 1;
					max_num[coordinate[i][j].front].now_x = j;
					max_num[coordinate[i][j].front].now_y = i;
				} 
				else{
					for(r=1; num-r>0; r++){
						if (coordinate[i][j].back == coordinate[i+r][j+k].front){//直接不跟同一塊積木的比 
						temp_height = coordinate[i-r][j-k].height +1;
						coordinate[i][j].prev_x =j-k;
						coordinate[i][j].prev_y =i-r;
						if(temp_height>max_height){
							max_height=temp_height;
						}
						}
						
					}			
				}

			}
		}*/

				
				
			}
			for(r=0; r<6;r++){ //將temp_maxnum存入，把max_num系列改一改
			 coordinate[i][r].height = temp_maxnum[r];
    		 coordinate[i][r].prev_x = temp_prev_x[r];
    		 coordinate[i][r].prev_y = temp_prev_y[r];

    		if(temp_maxnum[r] > max_num[coordinate[i][r].front].height){
       		 max_num[coordinate[i][r].front].height = temp_maxnum[r];
       		 max_num[coordinate[i][r].front].now_x = r;
      		 max_num[coordinate[i][r].front].now_y = i;
    		}

    		if(temp_maxnum[r] > final_max.height){
     		 final_max.height = temp_maxnum[r];
        	 final_max.now_x = r;
        	 final_max.now_y = i;
    		}
				
			}
				
		}
		printf("Case #%d\n", count);
		count+=1;
		printf("%d\n", final_max.height);
		// 建立一個暫存路徑的陣列
		items result_path[MAX];
		int path_len = 0;
        int current_y = final_max.now_y;
        int current_x = final_max.now_x;
        while(current_y != -1) {
            // 將當前積木資訊存入路徑陣列
            result_path[path_len].now_y = current_y;
            result_path[path_len].now_x = current_x;
            path_len++;

            // 移動到下一個積木
            int temp_y = current_y; // 必須用暫存變數
            current_y = coordinate[temp_y][current_x].prev_y;
            current_x = coordinate[temp_y][current_x].prev_x;
        }
		// 反向印出路徑 (從 i = path_len - 1 到 0)
        for(i = 0; i < path_len; i++) {
            int block_id = result_path[i].now_y + 1;
            int face_id = result_path[i].now_x;

            if(face_id == 0) printf("%d front\n", block_id);
            else if(face_id == 1) printf("%d back\n", block_id);
            else if(face_id == 2) printf("%d left\n", block_id);
            else if(face_id == 3) printf("%d right\n", block_id);
            else if(face_id == 4) printf("%d top\n", block_id);
            else if(face_id == 5) printf("%d bottom\n", block_id);
        }
	
		
		printf("\n");
		
	}
	
} 
