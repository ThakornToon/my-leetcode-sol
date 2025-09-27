class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = INT_MIN, min_val = INT_MAX;
        bool flag = false;
        
        // หาค่าต่ำสุดในส่วนที่ผิดลำดับ
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1])
                flag = true;
            if (flag)
                min_val = min(min_val, nums[i]);
        }
        
        flag = false;
        // หาค่าสูงสุดในส่วนที่ผิดลำดับ  
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > nums[i+1])
                flag = true;
            if (flag)
                max_val = max(max_val, nums[i]);
        }
        
        // หาตำแหน่งที่ถูกต้องสำหรับ min_val
        int left;
        for (left = 0; left < n; left++) {
            if (min_val < nums[left])
                break;
        }
        
        // หาตำแหน่งที่ถูกต้องสำหรับ max_val
        int right;
        for (right = n-1; right >= 0; right--) {
            if (max_val > nums[right])
                break;
        }
        
        return (right - left < 0) ? 0 : right - left + 1;
    }
};