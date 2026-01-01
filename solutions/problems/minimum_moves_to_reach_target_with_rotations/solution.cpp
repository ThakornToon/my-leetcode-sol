class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // สถานะเริ่มต้น: หัวที่ (0,1), หางที่ (0,0), แนวนอน
        // เก็บเป็น tuple (tail_r, tail_c, direction)
        // direction: 0 = แนวนอน (หัวอยู่ทางขวาของหาง), 1 = แนวตั้ง (หัวอยู่ทางใต้ของหาง)
        tuple<int, int, int> start = {0, 0, 0}; // สถานะของหางและทิศของหัว
        
        // เป้าหมาย: หางที่ (n-1, n-2), หัวที่ (n-1, n-1), แนวนอน
        tuple<int, int, int> target = {n-1, n-2, 0};
        
        // BFS
        queue<tuple<int, int, int>> q;
        unordered_set<string> visited;
        
        q.push(start);
        visited.insert(encode(start));
        
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [r, c, dir] = q.front();
                q.pop();
                
                // ตรวจสอบว่าถึงเป้าหมายหรือยัง
                if (make_tuple(r, c, dir) == target) {
                    return moves;
                }
                
                // สร้างสถานะต่อไป
                vector<tuple<int, int, int>> nextStates;
                
                // 1. ขยับขวา
                if (canMoveRight(r, c, dir, n, grid)) {
                    nextStates.push_back({r, c+1, dir});
                }
                
                // 2. ขยับลง
                if (canMoveDown(r, c, dir, n, grid)) {
                    nextStates.push_back({r+1, c, dir});
                }
                
                // 3. หมุนตามเข็มนาฬิกา (แนวนอน → แนวตั้ง)
                if (canRotateClockwise(r, c, dir, n, grid)) {
                    nextStates.push_back({r, c, 1});
                }
                
                // 4. หมุนทวนเข็มนาฬิกา (แนวตั้ง → แนวนอน)
                if (canRotateCounterClockwise(r, c, dir, n, grid)) {
                    nextStates.push_back({r, c, 0});
                }
                
                // เพิ่มสถานะต่อไปใน queue
                for (auto& state : nextStates) {
                    string key = encode(state);
                    // สถานะนี้เคยคิดไปรึยัง
                    if (visited.find(key) == visited.end()) {
                        visited.insert(key);
                        q.push(state);
                    }
                }
            }
            
            moves++;
        }
        
        return -1;  // ไม่สามารถไปถึงเป้าหมายได้
    }
    
private:
    string encode(const tuple<int, int, int>& state) {
        auto [r, c, dir] = state;
        return to_string(r) + "," + to_string(c) + "," + to_string(dir);
    }
    
    bool canMoveRight(int r, int c, int dir, int n, vector<vector<int>>& grid) {
        if (dir == 0) { // แนวนอน: หางที่ (r,c), หัวที่ (r,c+1)
            // ตรวจสอบว่าหัวสามารถขยับขวาได้
            if (c + 2 >= n) return false;
            return grid[r][c+2] == 0;
        } else { // แนวตั้ง: หางที่ (r,c), หัวที่ (r+1,c)
            // ทั้งหัวและหางต้องขยับขวาได้
            if (c + 1 >= n) return false;
            return grid[r][c+1] == 0 && grid[r+1][c+1] == 0;
        }
    }
    
    bool canMoveDown(int r, int c, int dir, int n, vector<vector<int>>& grid) {
        if (dir == 0) { // แนวนอน: หางที่ (r,c), หัวที่ (r,c+1)
            // ทั้งหัวและหางต้องขยับลงได้
            if (r + 1 >= n) return false;
            return grid[r+1][c] == 0 && grid[r+1][c+1] == 0;
        } else { // แนวตั้ง: หางที่ (r,c), หัวที่ (r+1,c)
            // ตรวจสอบว่าหัวสามารถขยับลงได้
            if (r + 2 >= n) return false;
            return grid[r+2][c] == 0;
        }
    }
    
    bool canRotateClockwise(int r, int c, int dir, int n, vector<vector<int>>& grid) {
        // หมุนตามเข็มนาฬิกา: แนวนอน → แนวตั้ง
        // ต้องมีพื้นที่ว่างใต้ทั้งสองช่อง
        if (dir != 0) return false; // ต้องเป็นแนวนอนเท่านั้น
        if (r + 1 >= n) return false; // ต้องมีแถวถัดไป
        
        return grid[r+1][c] == 0 && grid[r+1][c+1] == 0;
    }
    
    bool canRotateCounterClockwise(int r, int c, int dir, int n, vector<vector<int>>& grid) {
        // หมุนทวนเข็มนาฬิกา: แนวตั้ง → แนวนอน
        // ต้องมีพื้นที่ว่างทางขวาทั้งสองช่อง
        if (dir != 1) return false; // ต้องเป็นแนวตั้งเท่านั้น
        if (c + 1 >= n) return false; // ต้องมีคอลัมน์ถัดไป
        
        return grid[r][c+1] == 0 && grid[r+1][c+1] == 0;
    }
};