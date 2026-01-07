class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        
        // สร้าง board เพื่อเก็บตำแหน่ง queens
        vector<vector<bool>> board(8, vector<bool>(8, false));
        
        // เก็บตำแหน่ง queens ใน board
        for (const auto& queen : queens) {
            board[queen[0]][queen[1]] = true;
        }
        
        // ทิศทางทั้ง 8 (8 directions)
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},  // ซ้ายบน, บน, ขวาบน
            {0, -1},           {0, 1},   // ซ้าย,        ขวา
            {1, -1},  {1, 0},  {1, 1}    // ซ้ายล่าง, ล่าง, ขวาล่าง
        };
        
        int kingRow = king[0];
        int kingCol = king[1];
        
        // สำรวจแต่ละทิศทาง
        for (const auto& dir : directions) {
            int row = kingRow + dir.first;
            int col = kingCol + dir.second;
            
            // เดินไปเรื่อยๆ จนกว่าจะออกนอกกระดานหรือพบ queen
            while (row >= 0 && row < 8 && col >= 0 && col < 8) {
                if (board[row][col]) {
                    // พบ queen ในทิศทางนี้
                    result.push_back({row, col});
                    break;  // หยุดค้นหาในทิศทางนี้
                }
                
                // เดินต่อไปในทิศทางเดิม
                row += dir.first;
                col += dir.second;
            }
        }
        
        return result;
    }
};