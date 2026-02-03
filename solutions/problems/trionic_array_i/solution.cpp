class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
    
        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // ต้องมี increasing part (i > 0)
        if (i == 0 || i == n - 1) {
            return false;
        }
        
        // i ตอนนี้คือ peak (ตำแหน่งสูงสุด)
        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        // ต้องมี decreasing part (i > 0)
        if (i == 0 || i == n - 1) {
            return false;
        }

        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // ต้องเดินถึงตัวสุดท้าย
        return (i == n - 1);
    }
};