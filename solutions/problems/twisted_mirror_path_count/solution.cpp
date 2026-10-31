class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        
        // dp[r][c][0] = จำนวนวิธีที่ออกจาก (r,c) ไปทางขวา
        // dp[r][c][1] = จำนวนวิธีที่ ออกจาก (r,c) ไปทางล่าง
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
        
        // จุดเริ่มต้น (0, 0) สมมติว่าตั้งต้นเดินทางได้ทั้งสองทิศทางหลัก
        if (grid[0][0] == 0) {
            dp[0][0][0] = 1;
            dp[0][0][1] = 1;
        }
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) continue;

                long long from_left = (c > 0) ? dp[r][c - 1][0] : 0; // คนที่พุ่งขวามาถึงช่องนี้
                long long from_up   = (r > 0) ? dp[r - 1][c][1] : 0; // คนที่พุ่งลงมาถึงช่องนี้

                if (grid[r][c] == 1) {
                    // กระจก: มาจากซ้าย -> บังคับลงล่าง, มาจากบน -> บังคับไปขวา
                    dp[r][c][1] = from_left;
                    dp[r][c][0] = from_up;
                } else {
                    // ช่องว่าง: คนที่มาถึงไม่ว่าทิศไหน เลือกไปขวาหรือลงต่อได้อิสระ
                    long long total = (from_left + from_up) % MOD;
                    dp[r][c][0] = total;
                    dp[r][c][1] = total;
                }
            }
        }
        
        // ปลายทางเป็นช่องว่าง: จำนวนวิธีที่มาถึง = from_left + from_up
        if (m == 1 && n == 1) return 1;
        long long from_left = (n > 1) ? dp[m - 1][n - 2][0] : 0;
        long long from_up   = (m > 1) ? dp[m - 2][n - 1][1] : 0;
        return (from_left + from_up) % MOD;
    }
};