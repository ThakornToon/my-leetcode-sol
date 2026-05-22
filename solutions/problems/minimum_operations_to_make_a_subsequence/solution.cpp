class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        
        // map value to its index in target
        for (int i = 0; i < n; i++) {
            pos[target[i]] = i;
        }
        
        // สร้าง array ของ indices ที่ปรากฏใน arr
        vector<int> indices;
        for (int val : arr) {
            if (pos.count(val)) {
                indices.push_back(pos[val]);
            }
        }
        // target = [3, 8, 2]
        // arr = [1, 3, 4, 2, 8, 3, 5, 8, 2]
        // indices = [0, 2, 1, 0, 1, 2]
        
        // หา LIS ของ indices (Longest Increasing Subsequence)
        vector<int> lis;  // 
        for (int idx : indices) {
            // binary search หาตำแหน่งแรกที่เจอค่ามากกว่า
            auto it = lower_bound(lis.begin(), lis.end(), idx);
            
            if (it == lis.end()) {  // เอามาต่อท้ายได้
                lis.push_back(idx);
            } else {  // เคยสร้างลำดับมาแล้วแต่อันนี้อาจดีกว่า
                // [0, 2, 3] เจอ 1 -> [0, 1, 3]
                *it = idx;
            }
        }
        
        return n - lis.size();
    }
};