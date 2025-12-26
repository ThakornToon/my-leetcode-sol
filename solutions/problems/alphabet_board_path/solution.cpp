class Solution {
public:
    string alphabetBoardPath(string target) {
        string result;
        int x = 0, y = 0;  // ตำแหน่งปัจจุบัน (row, col)
        
        for (char c : target) {
            int idx = c - 'a';
            int nx = idx / 5;  // row ใหม่
            int ny = idx % 5;  // col ใหม่
            
            // ซ้าย/ขวา ก่อน (เว้นแต่จะอยู่ที่ z)
            if (x == 5 && y == 0) {
                // อยู่ที่ z: ต้องขึ้นก่อน
                addMoves('U', x - nx, result);
                x = nx;
                addMoves('R', ny - y, result);
                y = ny;
            } else {
                // ซ้าย/ขวา ก่อน
                addMoves('L', y - ny, result);  // ซ้ายถ้า y > ny
                addMoves('R', ny - y, result);  // ขวาถ้า ny > y
                y = ny;
                
                // ขึ้น/ลง หลัง
                addMoves('U', x - nx, result);  // ขึ้นถ้า x > nx
                addMoves('D', nx - x, result);  // ลงถ้า nx > x
                x = nx;
            }
            
            result += '!';
        }
        
        return result;
    }
private:
    void addMoves(char move, int count, string& result) {
        for (int i = 0; i < count; i++) {
            result += move;
        }
    }
};