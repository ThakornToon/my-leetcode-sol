class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        /* 
        dp[x][y][z] พิจารณาตั้งแต่วันที่ x โดยเหลือการดำเนินการ y และสถานะ z จะได้กำไรเท่าไร
        z = 0 ว่าง
        z = 1 buy
        z = 2 short sell
        */
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>> (k + 1, vector<long long> (3, INT_MIN)));

        // วันที่ n ไว้พิจารณาในวันที่ n - 1
        for (int i = 0; i <= k; i++){
            dp[n][i][0] = 0;
        }

        // ทำจากอนาคตย้อยมายังอดีต
        for (int i = n - 1; i >= 0; i--) { // เริ่มพิจารณาตั้งที่วันที่ n - 1 ไล่ลงมาถึงวันที่่ 0
            for (int j = 0; j <= k; j++) { // กรณีเหลือการดำเนินการอีก j ครั้ง
                // State 0: ไม่ทำอะไร, พิจารณาก่อน buy/sell ในวันนั้น โดยอิงจาก State 1, 2 ในอนาคต
                dp[i][j][0] = dp[i + 1][j][0];
                dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][1] - prices[i]); // buy
                dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][2] + prices[i]); // sell

                // States 1 กับ 2: ค้างไว้จากอนาคต
                dp[i][j][1] = dp[i + 1][j][1]; 
                dp[i][j][2] = dp[i + 1][j][2];
                if (j > 0){ 
                    // State 1: พิจารณาจาก state 0 ก่อนเข้าสู่การดำเนินการ
                    dp[i][j][1] = max(dp[i + 1][j][1], dp[i + 1][j - 1][0] + prices[i]);
                    // State 2: พิจารณาจาก state 0 ก่อนเข้าสู่การดำเนินการ
                    dp[i][j][2] = max(dp[i + 1][j][2], dp[i + 1][j - 1][0] - prices[i]);
                } 
            }
        }
        return dp[0][k][0]; // วันที่ 0 ดำเนินการเหลือ k ครั้ง สถานะว่าง (จุดเริ่มต้น)
    }
};