class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // ชุดทิศทาง: north, east, south, west
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        // เก็บอุปสรรคใน hash set
        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        int x = 0, y = 0;
        int direction = 0; // 0 = north
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) { // turn left
                direction = (direction + 3) % 4;
            } else if (cmd == -1) { // turn right
                direction = (direction + 1) % 4;
            } else { // move forward
                for (int step = 0; step < cmd; step++) {
                    int nextX = x + dx[direction];
                    int nextY = y + dy[direction];
                    
                    string key = to_string(nextX) + "," + to_string(nextY);
                    
                    // ตรวจสอบอุปสรรค
                    if (obstacleSet.find(key) != obstacleSet.end()) {
                        break; // หยุดหากเจออุปสรรค
                    }
                    
                    x = nextX;
                    y = nextY;
                    
                    // อัพเดตระยะทางสูงสุด
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};