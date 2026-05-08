class Solution {
private:
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        // queue เก็บ pair (index, distance)
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push({0, 0});
        visited[0] = true;
        
        // จัดกลุ่ม indices ตามค่าใน nums ที่มี (ไว้เช็ค index ที่ teleport ไปถึงได้)
        unordered_map<int, vector<int>> valToIndices;
        for (int i = 0; i < n; i++) {
            valToIndices[nums[i]].push_back(i);
        }
        
        unordered_map<int, bool> primeVisited;
        
        // BFS
        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            
            if (curr == n - 1) return dist;
            
            // Adjacent steps i+1 & i-1
            if (curr > 0 && !visited[curr - 1]) {  // ถอยได้
                visited[curr - 1] = true;
                q.push({curr - 1, dist + 1});
            }
            if (curr + 1 < n && !visited[curr + 1]) {  // เดินหน้าได้
                visited[curr + 1] = true;
                q.push({curr + 1, dist + 1});
            }
            
            // Prime teleportation
            int p = nums[curr];
            if (isPrime(p) && !primeVisited[p]) {
                primeVisited[p] = true;
                // หาทุกจำนวนที่หารด้วย p ลงตัว
                for (int mult = p; mult <= maxEle; mult += p) {
                    // ดูว่ามีใน nums ให้ teleport ไหม
                    if (valToIndices.count(mult)) {
                        for (int idx : valToIndices[mult]) {
                            if (!visited[idx]) {
                                visited[idx] = true;
                                q.push({idx, dist + 1});
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};