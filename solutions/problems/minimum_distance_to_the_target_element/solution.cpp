class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int d = 0; d < nums.size(); d++) {
            // ตรวจสอบทางซ้าย
            if (start - d >= 0 && nums[start - d] == target) {
                return d;
            }
            // ตรวจสอบทางขวา
            if (start + d < nums.size() && nums[start + d] == target) {
                return d;
            }
        }
        return -1;
    }
};