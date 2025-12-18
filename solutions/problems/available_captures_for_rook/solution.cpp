class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // Find rook position
        int rx = -1, ry = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                    break;
                }
            }
            if (rx != -1) break;
        }
        
        int count = 0;
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for (auto [dx, dy] : dirs) {
            int x = rx + dx;
            int y = ry + dy;
            
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'p') {
                    count++;
                    break;
                } else if (board[x][y] == 'B') {
                    break;
                }
                x += dx;
                y += dy;
            }
        }
        
        return count;
    }
};