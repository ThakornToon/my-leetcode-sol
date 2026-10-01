class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        // ให้ dp[i][j] คือจำนวนอาร์เรย์ที่ประกอบด้วยตัวเลขจาก 1 ถึง i ที่มีจำนวน Inverse Pairs เท่ากับ j
        // เมื่อมีอาเรย์ตัวเลข 1 ถึง i-1 แล้วจะเพิ่ม i ไปแทรก dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-min(j, i-1)]
        vector<int> dp(k + 1, 0);  // เราลดให้เหลือใช้แค่ dp[j]
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            vector<int> next_dp(k + 1, 0);
            long long sum = 0;

            // เราจะเอาแค่ตั้งแต่ j-min(j, i-1) ถึง j นั้นๆ โดย j มีตั้งแต่ 0 ถึง k
            for (int j = 0; j <= k; ++j) {
                sum += dp[j];
                //  ถ้าขนาด window (j) เกิน i-1 ให้ปรับลง
                if (j > i - 1) {
                    sum -= dp[j - i];
                }
                // จัดการค่าติดลบก่อนทำ Modulo
                sum = (sum % MOD + MOD) % MOD;
                next_dp[j] = sum;
            }
            dp = std::move(next_dp);
        }

        return dp[k];
    }
};