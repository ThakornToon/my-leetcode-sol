class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = k - 1;
        int minDiff = INT_MAX;
        
        while (right < nums.size()) {
            int diff = nums[right] - nums[left];
            minDiff = min(minDiff, diff);
            
            left++;
            right++;
        }
        
        return minDiff;
    }
};