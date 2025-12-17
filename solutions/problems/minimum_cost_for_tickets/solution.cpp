class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            // ซื้อตั๋ว 1 วัน
            dp[i+1] = min(dp[i+1], dp[i] + costs[0]);
            
            // ซื้อตั๋ว 7 วัน: ครอบคลุมถึงวัน j ที่ days[j] <= days[i] + 6
            int j = i;
            while (j < n && days[j] <= days[i] + 6) {
                dp[j+1] = min(dp[j+1], dp[i] + costs[1]);
                j++;
            }
            
            // ซื้อตั๋ว 30 วัน: ครอบคลุมถึงวัน k ที่ days[k] <= days[i] + 29
            j = i;
            while (j < n && days[j] <= days[i] + 29) {
                dp[j+1] = min(dp[j+1], dp[i] + costs[2]);
                j++;
            }
        }
        return dp[n];
    }
};