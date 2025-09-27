class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();
        int max_dist = 0;
        
        for (int i = 1; i < arrays.size(); i++) {
            int current_min = arrays[i].front();
            int current_max = arrays[i].back();
            
            // คำนวณระยะทางกับ min และ max ที่มีอยู่
            max_dist = max(max_dist, abs(current_max - min_val));
            max_dist = max(max_dist, abs(max_val - current_min));
            
            // อัปเดต min และ max global
            min_val = min(min_val, current_min);
            max_val = max(max_val, current_max);
        }
        
        return max_dist;
    }
};