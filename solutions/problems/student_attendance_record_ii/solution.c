#define MOD 1000000007

int checkRecord(int n) {
    // dp[j][k] แทนจำนวนวิธีที่ถูกต้องสำหรับวันที่ผ่านมา โดยมีขาดเรียน j ครั้ง และมาสายติดต่อกัน k ครั้ง
    int dp[2][3] = {0};

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) { 
        int new_dp[2][3] = {0}; // วันที่ i โดยจะพิจารณาต่อมาเมื่อวาน

        for (int a = 0; a < 2; ++a) { // Absent
            for (int l = 0; l < 3; ++l) { // Late

                // เพิ่ม 'P' (Present)
                new_dp[a][0] = (new_dp[a][0] + dp[a][l]) % MOD;

                // เพิ่ม 'A' (Absent) ถ้ายังไม่เกิน 1 ครั้ง
                if (a + 1 < 2) {
                    new_dp[a + 1][0] = (new_dp[a + 1][0] + dp[a][l]) % MOD;
                }

                // เพิ่ม 'L' (Late) ถ้ายังไม่ต่อเนื่อง 2 ครั้ง
                if (l + 1 < 3) {
                    new_dp[a][l + 1] = (new_dp[a][l + 1] + dp[a][l]) % MOD;
                }
            }
        }
        // เอาข้อมูลที่ update ไปเก็บใน dp
        memcpy(dp, new_dp, sizeof(dp));
    }

    int total = 0;
    // คิดทุกกรณีที่เป้นไปได้เมื่อมาถึงวันสุดท้าย
    for (int a = 0; a < 2; ++a) {
        for (int l = 0; l < 3; ++l) {
            total = (total + dp[a][l]) % MOD;
        }
    }

    return total;
}