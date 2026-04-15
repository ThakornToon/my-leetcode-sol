class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // สร้าง map จัดกลุ่ม indices ตามค่า
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[arr[i]].push_back(i);
        }
        
        // BFS
        vector<int> dist(n, -1);
        queue<int> q;
        
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            // index ที่คิดปัจจุบัน
            int curr = q.front();
            q.pop();
            
            // ถึง index สุดท้าย
            if (curr == n - 1) {
                return dist[curr];
            }
            
            // กระโดดไป i+1
            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
            
            // กระโดดไป i-1
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }
            
            // กระโดดไป indices ที่มีค่าเท่ากัน
            int val = arr[curr];
            if (groups.count(val)) {
                for (int next : groups[val]) {
                    if (dist[next] == -1) {
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                    }
                }
                // ลบกลุ่มนี้เพื่อไม่ให้เยือนซ้ำ
                groups.erase(val);
            }
        }
        
        return -1;
    }
};