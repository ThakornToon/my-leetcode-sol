class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        
        // เก็บตำแหน่งของแต่ละค่า
        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        
        // สำหรับแต่ละค่าที่มีอย่างน้อย 3 ตัว
        for (auto& [val, pos] : positions) {
            if (pos.size() < 3) continue;
            
            for (int a = 0; a < pos.size(); a++) {
                for (int b = a + 1; b < pos.size(); b++) {
                    for (int c = b + 1; c < pos.size(); c++) {
                        int dist = abs(pos[a] - pos[b]) + 
                                   abs(pos[b] - pos[c]) + 
                                   abs(pos[c] - pos[a]);
                        minDist = min(minDist, dist);
                    }
                }
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};