class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Calculate window sums
        vector<int> window(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) window[i - k + 1] = sum;
        }
        
        // Left array: best index up to i
        vector<int> left(n, 0);
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (window[i] > window[best]) best = i;
            left[i] = best;
        }
        
        // Right array: best index from i to end
        vector<int> right(n, 0);
        best = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (window[i] >= window[best]) best = i;
            right[i] = best;
        }
        
        // Try all middle positions
        vector<int> result(3, 0);
        int maxSum = INT_MIN;
        
        for (int j = k; j <= n - 2 * k; j++) {
            int i = left[j - k];
            int l = right[j + k];
            int total = window[i] + window[j] + window[l];
            
            if (total > maxSum) {
                maxSum = total;
                result = {i, j, l};
            }
        }
        
        return result;
    }
};