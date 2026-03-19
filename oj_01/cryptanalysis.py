
n = int(input())
all_text = ""

for _ in range(n):
    line = input()
    all_text += line

dictionary_c = {}
#.get(key, default_value):
#試著去字典裡找 upper_char 這個 key
#找到了，就回傳它對應的 value
#找不到，就回傳我們給的default_value 0

for char in all_text:
    if char.isalpha():
        upper_alp = char.upper()
        count= dictionary_c.get(upper_alp, 0)
        dictionary_c[upper_alp] = count+1

#.items() 會將字典的 (key, value) 對轉換成一個一個的元組 (tuple)
#list() 會將這些元組集合轉成一個列表

data_to_sort = list(dictionary_c.items())

#sorted():
#允許我們提供一個 key 來自訂排序的規則。這個 k

#lambda item: (-item[1], item[0])
#lambda 現在要定義一個匿名函數
#item 這個匿名函數接收一個參數，我們臨時叫它 item。
#: 接下來的內容是這個函數要做的事。
#(-item[1], item[0]) 函數要執行的運算，並把運算的結果回傳


sorted_list = sorted(data_to_sort, key = lambda item :(-item[1], item [0]))

#f f-string
#1.在字串的開頭引號 ( " 或 ' ) 前面加上一個 f
#2.在字串中，任何你想嵌入變數或運算式的地方，直接用大括號 {} 把它包起來。
#看到這個 f 開頭的字串時，它會自動去尋找裡面的 {}，然後把 {} 裡面的東西當成程式碼來執行，並將執行後的結果填回那個位置
for items in sorted_list:
    print(f"{items[0]} {items[1]}")