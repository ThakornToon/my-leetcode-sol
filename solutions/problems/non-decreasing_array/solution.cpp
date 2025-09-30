class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modifications = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                modifications++;
                
                if (modifications > 1) {
                    return false;
                }
                
                // Decision: modify nums[i] or nums[i+1]?
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    // Case: [3, 4, 2] -> better to raise nums[i+1]
                    nums[i + 1] = nums[i];
                } else {
                    // Case: [1, 4, 2] -> better to lower nums[i]
                    nums[i] = nums[i + 1];
                }
            }
        }
        
        return true;
    }
};