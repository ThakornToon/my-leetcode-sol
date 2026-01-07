class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int MOD = 1e9 + 7;
        const int FACES = 6;
        const int MAX_CONS = 15; // จาก constraints: rollMax[i] ≤ 15
        
        // dp[len][last][cons] = จำนวนลำดับความยาว len ที่ลงท้ายด้วยหน้า last ติดต่อกัน cons ครั้ง
        vector<vector<vector<long long>>> dp(
            n + 1, 
            vector<vector<long long>>(
                FACES,
                vector<long long>(MAX_CONS + 1, 0)
            )
        );
        
        // Base case: ความยาว 1
        for (int face = 0; face < FACES; face++) {
            dp[1][face][1] = 1;
        }
        
        // Fill DP table
        for (int len = 2; len <= n; len++) {
            for (int last = 0; last < FACES; last++) {
                for (int cons = 1; cons <= rollMax[last]; cons++) {
                    long long ways = dp[len-1][last][cons] % MOD;
                    
                    // ลองทุกหน้าสำหรับการทอยถัดไป
                    for (int next = 0; next < FACES; next++) {
                        // เปลี่ยนหน้าใหม่: dp[len][newFace][1] += dp[len-1][oldFace][k] สำหรับทุก k
                        // ใช้หน้าเดิม: dp[len][face][k] += dp[len-1][face][k-1] ถ้า k > 1
                        if (next == last) {
                            // ใช้หน้าเดิม: ต้องไม่เกิน rollMax
                            if (cons + 1 <= rollMax[last]) {
                                dp[len][next][cons + 1] = 
                                    (dp[len][next][cons + 1] + ways) % MOD;
                            }
                        } else {
                            // เปลี่ยนหน้าใหม่: เริ่มนับใหม่ที่ 1
                            dp[len][next][1] = 
                                (dp[len][next][1] + ways) % MOD;
                        }
                    }
                }
            }
        }
        
        // รวมผลลัพธ์ลำดับความยาว n ทุกกรณี
        long long result = 0;
        for (int face = 0; face < FACES; face++) {
            for (int cons = 1; cons <= rollMax[face]; cons++) {
                result = (result + dp[n][face][cons]) % MOD;
            }
        }
        
        return result;
    }
};