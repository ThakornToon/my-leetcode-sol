class Solution {
public:
    int minimumOneBitOperations(int n) {
        // G = n ⊕ (n >> 1)
        // G ⊕ (G >> 1) = [n ⊕ (n>>1)] ⊕ [(n ⊕ (n>>1)) >> 1]
        // สมบัติ: (a ⊕ b) >> 1 = (a >> 1) ⊕ (b >> 1) เพราะการ shift ขวาแจกแจงได้กับ XOR
        // G ⊕ (G>>1) = n ⊕ (n>>2)
        // G ⊕ (G>>1) ⊕ (G>>2) = n ⊕ (n>>3)
        // G ⊕ (G>>1) ⊕ (G>>2) ⊕ (G>>3) = n ⊕ (n>>4)
        // ... จน (n >> k) = 0 ทำให้เหลือแค่ n

        // n = เลขฐานสอง (รูปฐานสิบ : 0, 1, 2, 3, ...)
        // Gray Code ตัวที่ n ปกติ: gray = n XOR (n>>1) 
        // Inverse Gray Code: n = gray XOR (gray>>1) XOR (gray>>2) XOR ...
        int gray = n;
        int result = 0;
        while (gray > 0) {
            result ^= gray;
            gray >>= 1;
        }
        return result;
    }
};