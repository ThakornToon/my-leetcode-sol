class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        
        // แปลงบอร์ดเป็น string
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        
        // ทิศทางการเลื่อน (ขึ้น, ขวา, ลง, ซ้าย)
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        unordered_set<string> visited;
        queue<pair<string, int>> q;  // {state, moves}
        
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();
            
            if (current == target) {
                return moves;
            }
            
            // หาตำแหน่งช่องว่าง (0)
            int zero_pos = current.find('0');
            int row = zero_pos / 3;
            int col = zero_pos % 3;
            
            // ลองเลื่อนทั้ง 4 ทิศทาง
            for (auto& dir : directions) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];
                
                if (new_row >= 0 && new_row < 2 && new_col >= 0 && new_col < 3) {
                    int new_pos = new_row * 3 + new_col;
                    
                    // สลับช่องว่างกับตัวเลขที่อยู่ติดกัน
                    string next_state = current;
                    swap(next_state[zero_pos], next_state[new_pos]);
                    
                    if (visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push({next_state, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};