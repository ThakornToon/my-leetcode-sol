class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        
        const int MOD = 1e9 + 7;
        
        // จัดกลุ่มปุ่มตาม symmetry:
        // A = {1, 3, 7, 9} (มุม)                ไปต่อได้สองทาง -> B C
        // B = {2, 8}       (ตรงกลางด้านข้าง)     ไปต่อได้สองทาง -> A
        // C = {4, 6}       (ตรงกลางด้านบน-ล่าง)  ไปต่อได้สามทาง -> A D
        // D = {0}          // เฉพาะ            ไปต่อได้สองทาง -> C
        // E = {5}          // ไม่ได้ใช้           ไปต่อไม่ได้     -> -
        
        // จากความสมมาตร: 1,3,7,9 เหมือนกัน, 2,8 เหมือนกัน, 4,6 เหมือนกัน
        // เราจึงเก็บแค่ 4 states: A, B, C, D
        
        // จำนวนวิธีในแต่ละ state
        long long A = 4;  // {1,3,7,9}
        long long B = 2;  // {2,8}
        long long C = 2;  // {4,6}
        long long D = 1;  // {0}
        
        for (int step = 2; step <= n; step++) {
            long long newA = (2 * B + 2 * C) % MOD;
            long long newB = (A) % MOD;
            long long newC = (A + 2 * D) % MOD;
            long long newD = (C) % MOD;
            
            A = newA;
            B = newB;
            C = newC;
            D = newD;
        }
        
        return (A + B + C + D) % MOD;
    }
};