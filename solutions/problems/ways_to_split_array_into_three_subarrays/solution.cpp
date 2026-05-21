class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long result = 0;
        int j = 1, k = 1;
        
        for (int i = 0; i < n - 2; i++) {
            int leftSum = prefix[i + 1];
            
            // ขยับ j ให้ prefix[j] - leftSum >= leftSum
            if (j < i + 2) j = i + 2;
            while (j < n && prefix[j] - leftSum < leftSum) {
                j++;
            }
            
            // ขยับ k ให้ prefix[k] - leftSum <= total - prefix[k]
            if (k < j) k = j;
            while (k < n && prefix[k] - leftSum <= prefix[n] - prefix[k]) {
                k++;
            }
            
            result = (result + (k - j)) % MOD;
        }
        
        return result;
    }
};