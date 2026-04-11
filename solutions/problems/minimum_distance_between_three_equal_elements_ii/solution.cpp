class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        
        for (auto& [val, pos] : positions) {
            int m = pos.size();
            if (m < 3) continue;
            
            // ระยะทาง = 2*(pos[c] - pos[a]) สำหรับ a < b < c
            // ดังนั้น b อยู่ตรงกลาง ไม่มีผลต่อระยะทางรวม
            // แค่ต้องมี b อยู่ระหว่าง a และ c เท่านั้น
            for (int a = 0; a < m; a++) {
                for (int c = a + 2; c < m; c++) {
                    // ตรวจสอบว่ามี b ระหว่าง a และ c
                    if (c - a >= 2) {
                        int dist = 2 * (pos[c] - pos[a]);
                        minDist = min(minDist, dist);
                        break;  // เพราะ c ยิ่งไกลยิ่งระยะทางมากขึ้น
                    }
                }
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};