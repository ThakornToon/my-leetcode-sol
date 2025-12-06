class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int m = group.size();
        
        // dp[i][j][k] พิจารณา i แผนแรก ใช้ไป j คน ได้กำไร k = จำนวนวิธี
        vector<vector<vector<int>>> dp(
            m + 1, 
            vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0))
        );
        
        // Base: ไม่มีแผน(i = 0) 0 คน 0 กำไร = 1 วิธี (ไม่ทำอะไร)
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= m; i++) { // พิจารณาแผน i ตำแหน่ง i-1
            int g = group[i-1];
            int p = profit[i-1];
            
            for (int j = 0; j <= n; j++) { // คนที่ใช้ในปัจจุบัน
                for (int k = 0; k <= minProfit; k++) { // กำไรที่ปัจจุบันได้
                    // ไม่เลือกแผนนี้
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    // เลือกแผนนี้ (ถ้ามีคนพอ)
                    if (j >= g) {
                        // เริ่มที่ 0 เลือกแผนกำไร 5 minProfit = 3 
                        // dp[i][j][3 (ควรเป็น 5 เราจำกัดที่ minProfit)] += dp[i - 1][j - g][0 (ควรเป็น -2 แต่จำกัดไว้)]
                        int prevProfit = max(k - p, 0);
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-g][prevProfit]) % MOD;
                    }
                }
            }
        }
        
        // Sum all ways using <= n people and profit >= minProfit
        // แต่ใน DP เราเก็บ profit ไว้ที่ minProfit สำหรับกำไรที่เกิน
        int ans = 0;
        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[m][j][minProfit]) % MOD;
        }
        return ans;
    }
};