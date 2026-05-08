class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        
        // prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + houses[i];
        }
        
        // precompute cost (optional: compute on the fly)
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) / 2;
                int leftCount = mid - i + 1;
                int rightCount = j - mid;
                int leftSum = prefix[mid + 1] - prefix[i];
                int rightSum = prefix[j + 1] - prefix[mid + 1];
        
                cost[i][j] =  (houses[mid] * leftCount - leftSum) + 
                   (rightSum - houses[mid] * rightCount);
            }
        }
        
        // 1D DP
        vector<int> prev(n), dp(n);
        
        for (int i = 0; i < n; i++) {
            prev[i] = cost[0][i];
        }
        
        for (int mail = 2; mail <= k; mail++) {
            for (int i = mail - 1; i < n; i++) {
                dp[i] = INT_MAX;
                for (int j = mail - 2; j < i; j++) {
                    if (prev[j] != INT_MAX) {
                        dp[i] = min(dp[i], prev[j] + cost[j + 1][i]);
                    }
                }
            }
            swap(dp, prev);
        }
        
        return prev[n - 1];
    }
};