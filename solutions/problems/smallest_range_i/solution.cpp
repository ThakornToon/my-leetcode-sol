class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = nums[0], max_val = nums[0];
    
        // หาค่าสูงสุดและต่ำสุด
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        // คำนวณคำตอบ
        int result = (max_val - k) - (min_val + k);
        return result > 0 ? result : 0;
    }
};