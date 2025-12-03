class Solution {
public:
    int mirrorReflection(int p, int q) {
        // กำจัด factor 2 ทั้งหมด
        while (p % 2 == 0 && q % 2 == 0) {
            p >>= 1;  // p /= 2
            q >>= 1;  // q /= 2
        }
        
        if (p % 2 == 0) return 2;  // p เป็นคู่
        if (q % 2 == 0) return 0;  // q เป็นคู่
        return 1;                  // ทั้งคู่เป็นคี่
    }
};