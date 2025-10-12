class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // จำนวนเฉพาะที่น้อยกว่าหรือเท่ากับ 20
        vector<bool> primes = {false, false, true, true, false, true, 
                              false, true, false, false, false, true,
                              false, true, false, false, false, true,
                              false, true, false};
        
        int count = 0;
        for (int num = left; num <= right; num++) {
            // นับจำนวน bit 1
            int bits = countBits(num);
            
            // ตรวจสอบว่าเป็นจำนวนเฉพาะไหม
            if (primes[bits]) {
                count++;
            }
        }
        return count;
    }
    
private:
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;  // ตรวจสอบ bit สุดท้าย
            n >>= 1;         // เลื่อนขวา
        }
        return count;
    }
};