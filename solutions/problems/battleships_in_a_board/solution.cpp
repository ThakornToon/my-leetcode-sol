/*
เราสามารถใช้เทคนิคการตรวจสอบเฉพาะ "หัวเรือ" (ส่วนเริ่มต้นของเรือ) เพื่อนับจำนวนเรือได้โดยไม่ต้องแก้ไขกระดาน:

หัวเรือ คือเซลล์ 'X' ที่:
ไม่มีเซลล์ 'X' ทางด้านบน (หรืออยู่แถวแรก)
ไม่มีเซลล์ 'X' ทางด้านซ้าย (หรืออยู่คอลัมน์แรก)
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    // ตรวจสอบว่าเป็นหัวเรือหรือไม่
                    bool is_head = true;
                    if (i > 0 && board[i-1][j] == 'X') is_head = false;
                    if (j > 0 && board[i][j-1] == 'X') is_head = false;
                    
                    if (is_head) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};