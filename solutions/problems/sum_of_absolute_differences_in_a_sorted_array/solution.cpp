class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // คำนวณ prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
                
        for (int i = 0; i < n; i++) {
            int leftCount = i;
            int rightCount = n - i - 1;
            
            int leftSum = leftCount * nums[i] - prefix[i];
            int rightSum = (prefix[n] - prefix[i + 1]) - rightCount * nums[i];
            
            result[i] = leftSum + rightSum;
        }
        
        return result;
    }
};