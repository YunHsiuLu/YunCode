# 前情提要
這邊的練習純粹是為了解題<br>
並沒有考慮到效率或是可讀性（當然我有儘量地顧及可讀性）或是程式結構<br>
以下會解說三個題目的解題方向：<br>
Compile code: `make`<br>
Run the certain exercise: `./XXXXX.out`<br>

## Ancient Cipher
*參考檔案*`ancient_cipher.c`<br>
解題思路：<br>
1. scanf輸入的cipher text及plain text
2. 對cipher及plain進行分析，我這邊是分析字母數量，以及對相對應的字母數量及字母進行排序，使用的排序法是insertion sort。
3. 排序好之後，只需要對最多數量的字母進行比對即可。
4. 比對方式：固定某一最多數量字母後，計算p&rarr;c的移動數量。然後往後面的字串進行比對。

