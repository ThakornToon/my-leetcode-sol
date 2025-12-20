/*
1 ล้าน = 10^6 -> r * c = 10^12 เป็นไปไม่ได้ที่จะค้นหาแบบ DFS/BFS ทั่วทั้งตาราง
มีเซลล์ที่ถูกบล็อกได้สูงสุด 200 เซลล์
หากเซลล์ที่ถูกบล็อกอยู่ติดกัน พวกมันสามารถล้อมรอบพื้นที่ได้
พื้นที่ที่ถูกล้อมรอบมีขนาดจำกัด (เนื่องจากมีจำนวนเซลล์ที่ถูกบล็อกจำกัด)
พื้นที่ที่ใหญ่ที่สุดที่สามารถล้อมรอบได้คือพื้นที่รูปสามเหลี่ยม
*/

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<string> blockedSet;
        for (auto& b : blocked) {
            blockedSet.insert(to_string(b[0]) + "," + to_string(b[1]));
        }
        
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
private:
    const long long BOUNDARY = 1000000;
    
    bool bfs(vector<int>& start, vector<int>& end, unordered_set<string>& blockedSet) {
        const int MAX_VISIT = blockedSet.size() * blockedSet.size() / 2;
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        
        q.push({start[0], start[1]});
        visited.insert(to_string(start[0]) + "," + to_string(start[1]));
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // If we've visited enough cells, we can escape
            if (visited.size() > MAX_VISIT) {
                return true;
            }
            
            // If reached target
            if (x == end[0] && y == end[1]) {
                return true;
            }
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                // Check bounds
                if (nx < 0 || nx >= BOUNDARY || ny < 0 || ny >= BOUNDARY) {
                    continue;
                }
                
                string key = to_string(nx) + "," + to_string(ny);
                
                // Check if blocked or visited
                if (blockedSet.count(key) || visited.count(key)) {
                    continue;
                }
                
                visited.insert(key);
                q.push({nx, ny});
            }
        }
        
        return false;
    }
};