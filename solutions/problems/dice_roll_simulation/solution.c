#define MOD 1000000007
#define FACES 6
#define MAX_CONS 16

int dieSimulator(int n, int* rollMax, int rollMaxSize) {
    // dp[face][consecutive] = current face with consecutive
    long long dp[FACES][MAX_CONS];
    long long new_dp[FACES][MAX_CONS];
    
    memset(dp, 0, sizeof(dp));
    
    // เริ่มต้นความยาว 1
    for (int face = 0; face < FACES; face++) {
        dp[face][1] = 1;
    }
    
    // สำหรับความยาว 2 ถึง n
    for (int len = 2; len <= n; len++) {
        // Reset new_dp
        memset(new_dp, 0, sizeof(new_dp));
        
        // คำนวณ total จาก dp ก่อนหน้า
        long long total = 0;
        // คำนวณ sum ของหน้า f จาก dp ก่อนหน้า
        long long sumFaceF[FACES] = {0};

        // คำนวน totalม sumFaceF เพื่อหาจำนวนวิธี
        for (int f = 0; f < FACES; f++) {
            for (int c = 1; c <= rollMax[f]; c++) {
                sumFaceF[f] = (sumFaceF[f] + dp[f][c]) % MOD;
            }
            total = (total + sumFaceF[f]) % MOD;
        }
        
        // อัพเดท DP
        for (int newf = 0; newf < FACES; newf++) {
            // กรณีเปลี่ยนมาหน้าใหม่ f
            // มาจากหน้าอื่นทั้งหมด: total - sumFaceF
            new_dp[newf][1] = (total - sumFaceF[newf] + MOD) % MOD;
            
            // กรณีใช้หน้าเดิมต่อ
            for (int c = 2; c <= rollMax[newf]; c++) {
                new_dp[newf][c] = dp[newf][c - 1];
            }
        }
        
        // คัดลอก new_dp ไปยัง dp
        memcpy(dp, new_dp, sizeof(dp));
    }
    
    // รวมผลลัพธ์ทั้งหมดที่ความยาว n
    long long result = 0;
    for (int f = 0; f < FACES; f++) {
        for (int c = 1; c <= rollMax[f]; c++) {
            result = (result + dp[f][c]) % MOD;
        }
    }
    
    return (int)result;
}