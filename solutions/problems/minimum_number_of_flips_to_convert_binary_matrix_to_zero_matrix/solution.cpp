class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int totalCells = m * n;
        
        // แปลง matrix เป็น bitmask
        int startMask = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int pos = i * n + j;
                    startMask |= (1 << pos);
                }
            }
        }
        
        // ถ้าเป็น 0 หมดแล้ว
        if (startMask == 0) {
            return 0;
        }
        
        // BFS
        queue<pair<int, int>> q;  // {mask, steps}
        unordered_set<int> visited;
        
        q.push({startMask, 0});
        visited.insert(startMask);
        
        // directions สำหรับการ flip
        int dirs[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // รวมตัวเอง
        
        while (!q.empty()) {
            auto [mask, steps] = q.front();
            q.pop();
            
            // ลอง flip ทุกตำแหน่ง
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int newMask = mask;
                    
                    // flip ตำแหน่ง i,j และเพื่อนบ้าน
                    for (auto& dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            int pos = ni * n + nj;
                            newMask ^= (1 << pos);
                        }
                    }
                    
                    if (newMask == 0) {
                        return steps + 1;
                    }
                    
                    if (!visited.count(newMask)) {
                        visited.insert(newMask);
                        q.push({newMask, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};