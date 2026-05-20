class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);
        
        // LIS จากซ้าย (เพิ่ม)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
        
        // LDS จากขวา (ลด)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
        
        // หา mountain ที่ยาวที่สุด (ซ้ายเพิ่มขวาลด)
        int maxLen = 0;
        for (int i = 1; i < n - 1; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxLen = max(maxLen, LIS[i] + LDS[i] - 1);
            }
        }
        
        return n - maxLen;

    }
};