class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // low เป็น 0 ได้เสมอ
        int diff1 = nums[n - 3] - nums[0]; // เปลี่ยน 2 ตัวท้าย
        int diff2 = nums[n - 1] - nums[2]; // เปลี่ยน 2 ตัวหน้า
        int diff3 = nums[n - 2] - nums[1]; // เปลี่ยนหัว 1 ตัว ท้าย 1 ตัว
        
        return std::min({diff1, diff2, diff3});
    }
};