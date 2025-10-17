class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
private:
    int countSubarrays(vector<int>& nums, int bound) {
        int count = 0;
        int current = 0;
        
        for (int num : nums) {
            if (num <= bound) {
                current++;
                count += current;
            } else {
                current = 0;
            }
        }
        
        return count;
    }
};