class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // dp[i] เก็บค่ามากสุดของลำดับยาว 0 ถึง 
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int currentMax = 0;
            
            // ลองทุกความยาวของส่วนสุดท้าย
            for (int j = 1; j <= k && j <= i; j++) {
                currentMax = max(currentMax, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + currentMax * j);
            }
        }
        
        return dp[n];
    }
};