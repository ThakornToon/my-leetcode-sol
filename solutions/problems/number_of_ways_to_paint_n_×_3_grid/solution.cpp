class Solution {
public:
    int numOfWays(int n) {
        const long long mod = 1e9 + 7;
        // Type A (ABA): สีแรกและสีสามเหมือนกัน เช่น RGR, RBR, GRG, GBG, BRB, BGB → 6 แบบ
        // Type B (ABC): ทั้งสามสีต่างกันทั้งหมด เช่น RGB, RBG, GBR, GRB, BRG, BGR → 6 แบบ
        // dpA[i] = จำนวนวิธีสำหรับ i แถว โดยแถวสุดท้ายเป็น Type A
        // dpB[i] = จำนวนวิธีสำหรับ i แถว โดยแถวสุดท้ายเป็น Type B
        long long dpA = 6;  // สำหรับ n=1: Type A มี 6 วิธี
        long long dpB = 6;  // สำหรับ n=1: Type B มี 6 วิธี
        
        for (int i = 2; i <= n; i++) {
            long long newA = (3 * dpA + 2 * dpB) % mod;
            long long newB = (2 * dpA + 2 * dpB) % mod;
            dpA = newA;
            dpB = newB;
        }
        
        return (dpA + dpB) % mod;
    }
};