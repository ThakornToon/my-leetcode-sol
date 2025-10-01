class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_length = 1;
        int current_length = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                current_length++;
                max_length = max(max_length, current_length);
            } else {
                current_length = 1;
            }
        }
        
        return max_length;
    }
};