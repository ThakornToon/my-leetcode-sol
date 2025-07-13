class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // สร้าง DP table ขนาด (m+1) x (n+1) ว่าจะเลือกได้มากสุดกี่ตัว
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& s : strs) {
            // นับจำนวน 0 และ 1 ในสตริงปัจจุบัน
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            
            // อัพเดท DP table จากล่างขวาไปบนซ้าย
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};