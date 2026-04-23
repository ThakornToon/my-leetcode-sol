class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        // เรียงจากมากไปน้อย
        sort(nums.begin(), nums.end(), greater<int>());
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int subSum = 0;
        vector<int> result;
        
        for (int num : nums) {
            subSum += num;
            result.push_back(num);
            if (subSum > totalSum - subSum) {
                break;
            }
        }
        
        return result;
    }
};