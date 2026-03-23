/*
Summing Digits 
錯誤： 
int y, i, j; 
// 錯誤 1: y 沒給初始值就跑 y>=10，會讀到記憶體垃圾值
for(j=0; y>=10 || temp>=10; j++){
    int y = 0; // 錯誤 2: 重複定義 y，這會讓外面的 y 接收不到值
    for(i=0; (temp/10)>=0; i++){ // 錯誤 3: (0/10)>=0 永遠成立，死迴圈
        y+= temp %10;
        temp = temp/10;
    }
    // 錯誤 4: 算完一輪 y，沒把 y 給回 temp，下一輪 temp 永遠是 0
}

改善： 可利用printf放入回圈內檢查 
int y, i, j;
		if(temp< 10){
			printf("%lld", temp);
		}else{
			for(j=0; y>=10 || temp>=10; j++){
				y = 0;
				for(i=0; temp >0; i++){
					y+= temp %10;
					temp = temp/10;
				}
				temp = y;
			}
*/
