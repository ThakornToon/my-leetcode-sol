class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // แยกตัวเลขของ n
        vector<int> digits;
        int temp = n;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());
        int len = digits.size();
        
        // จำนวนที่ไม่มีตัวเลขซ้ำ
        int uniqueCount = 0;
        
        // 1. จำนวนที่มีหลักน้อยกว่า len
        for (int i = 1; i < len; i++) {
            uniqueCount += 9 * P(9, i - 1);
        }
        
        // 2. จำนวนที่มี len หลัก และ ≤ n
        vector<bool> used(10, false);
        bool validPrefix = true;
        
        for (int i = 0; i < len; i++) {
            int currentDigit = digits[i];
            int start = (i == 0) ? 1 : 0;
            
            // สำหรับแต่ละหลักที่น้อยกว่า currentDigit
            for (int d = start; d < currentDigit; d++) {
                if (!used[d]) {
                    // จำนวนวิธีเลือกตัวเลขที่เหลือ
                    uniqueCount += P(9 - i, len - i - 1);
                }
            }
            
            // ถ้า currentDigit ใช้ไปแล้ว break
            if (used[currentDigit]) {
                validPrefix = false;
                break;
            }
            used[currentDigit] = true;
        }
        
        // ถ้าทุกหลักของ n ไม่ซ้ำกัน นับ n เองด้วย
        if (validPrefix) {
            uniqueCount++;
        }
        
        return n - uniqueCount;
    }
    
private:
    // P(n, k) = n!/(n-k)!
    int P(int n, int k) {
        if (k == 0) return 1;
        
        int result = 1;
        for (int i = 0; i < k; i++) {
            result *= (n - i);
        }
        return result;
    }
};