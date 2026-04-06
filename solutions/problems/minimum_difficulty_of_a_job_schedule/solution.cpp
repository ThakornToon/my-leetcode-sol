class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d) return -1;
        
        // dp[i][j] = min difficulty สำหรับงาน i ตัวแรก แบ่งเป็น j วัน
        // ลดเหลือ dp[j] แล้วแยกคิดเอา
        vector<int> dp(n + 1, INT_MAX);
        
        // base case: 1 วัน
        int maxSoFar = 0;
        for (int i = 1; i <= n; i++) {
            maxSoFar = max(maxSoFar, jobDifficulty[i-1]);
            dp[i] = maxSoFar;
        }
        
        // คำนวณสำหรับ days = 2 ถึง d
        for (int days = 2; days <= d; days++) {
            vector<int> newDp(n + 1, INT_MAX);
            
            for (int i = days; i <= n; i++) {
                int maxInLast = 0;
                for (int j = i - 1; j >= days - 1; j--) {
                    maxInLast = max(maxInLast, jobDifficulty[j]);
                    if (dp[j] != INT_MAX) {
                        newDp[i] = min(newDp[i], dp[j] + maxInLast);
                    }
                }
            }
            
            dp = newDp;
        }
        
        return dp[n];
    }
};