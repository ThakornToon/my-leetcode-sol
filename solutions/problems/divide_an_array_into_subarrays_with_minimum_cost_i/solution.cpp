class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < min1) {
                min2 = min1;      // อัปเดตรองน้อยที่สุด
                min1 = nums[i];   // อัปเดตน้อยที่สุด
            } else if (nums[i] < min2) {
                min2 = nums[i];   // อัปเดตรองน้อยที่สุด
            }
        }
        
        return nums[0] + min1 + min2;
    }
};