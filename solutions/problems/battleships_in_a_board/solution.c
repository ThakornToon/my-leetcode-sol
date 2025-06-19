/*
เราสามารถใช้เทคนิคการตรวจสอบเฉพาะ "หัวเรือ" (ส่วนเริ่มต้นของเรือ) เพื่อนับจำนวนเรือได้โดยไม่ต้องแก้ไขกระดาน:

หัวเรือ คือเซลล์ 'X' ที่:
ไม่มีเซลล์ 'X' ทางด้านบน (หรืออยู่แถวแรก)
ไม่มีเซลล์ 'X' ทางด้านซ้าย (หรืออยู่คอลัมน์แรก)
*/
int countBattleships(char** board, int boardSize, int* boardColSize) {
    int count = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'X') {
                // ตรวจสอบว่าเป็นหัวเรือหรือไม่
                int is_head = 1;
                if (i > 0 && board[i-1][j] == 'X') {
                    is_head = 0;
                }
                if (j > 0 && board[i][j-1] == 'X') {
                    is_head = 0;
                }
                if (is_head) {
                    count++;
                }
            }
        }
    }
    return count;
}