class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] เก็บบิตเซตของค่า XOR ที่เป็นไปได้ทั้งหมดที่ช่อง (i, j)
        // ต้อง check ทุก bitset ที่เป็นไปได้ที่มาถึง (0 ถึง 1023)
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        
        dp[0][0].set(grid[0][0]);  // เปิดสถานะว่าค่า grid[0][0] เป็นไปได้
        
        // dp คิดทีละแถว
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                // ค่า XOR ทั้งหมดที่เป็นไปได้ ก่อนที่จะก้าวเข้ามาเหยียบช่อง (i, j) มีอะไรบ้าง
                bitset<1024> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];
                
                // XOR กับทุกค่าที่เป็นไปได้
                int val = grid[i][j];
                for (int v = 0; v < 1024; ++v) {
                    if (prev[v]) {
                        dp[i][j].set(v ^ val);
                    }
                }
            }
        }

        for (int v = 0; v < 1024; ++v) {
            // ตรวจสอบว่าค่า v เคยเกิดขึ้นหรือยัง ณ จุดสุดท้าย
            if (dp[m - 1][n - 1][v]) {
                return v;
            }
        }
        return 0;
    }
};