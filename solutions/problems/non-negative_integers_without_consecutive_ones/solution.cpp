class Solution {
public:
    int findIntegers(int n) {
        if (n < 2) return n + 1;
        
        // Fibonacci sequence: f[i] = จำนวนไบนารีสตริงยาว i บิตที่ไม่มี 11
        vector<int> fib(32);
        fib[0] = 1;  // ""
        fib[1] = 2;  // "0", "1"
        
        for (int i = 2; i < 32; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        int result = 0;
        int prev_bit = 0;
        
        // ตรวจสอบจากบิตสูงสุดไปต่ำสุด
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {  // บิตที่ i เป็น 1
                result += fib[i];
                
                if (prev_bit == 1) {
                    return result;  // พบ 11 → หยุดนับ
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        
        return result + 1;  // บวกตัว n เอง
    }
};