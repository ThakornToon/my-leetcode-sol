class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        bool sorted = true;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                sorted = false;
                if (ans == -1) {
                    ans = nums[i];
                } else {
                    ans &= nums[i];
                }
            }
        }
        
        if (sorted) return 0;
        return std::max(ans, 0);
    }
};