class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum_map;
        int count = 0;
        
        // คำนวณผลรวมจาก nums1 และ nums2
        for (int a : nums1) {
            for (int b : nums2) {
                sum_map[a + b]++;
            }
        }
        
        // ตรวจสอบผลรวมจาก nums3 และ nums4
        for (int c : nums3) {
            for (int d : nums4) {
                int target = - (c + d);
                if (sum_map.find(target) != sum_map.end()) {
                    count += sum_map[target];
                }
            }
        }
        
        return count;
    }
};