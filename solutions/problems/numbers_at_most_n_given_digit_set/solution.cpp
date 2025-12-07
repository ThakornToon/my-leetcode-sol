class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string n_str = to_string(n);
        int k = n_str.length();
        int d = digits.size();
        
        // แปลง digits เป็น vector<int>
        vector<int> digit_vals(d);
        for (int i = 0; i < d; i++) {
            digit_vals[i] = digits[i][0] - '0';
        }
        sort(digit_vals.begin(), digit_vals.end());
        
        // ตัวเลขที่มีจำนวนหลักน้อยกว่า k
        int result = 0;
        for (int len = 1; len < k; len++) {
            result += pow(d, len);
        }
        
        // ตัวเลขที่มีจำนวนหลักเท่ากับ k (<=n)
        // ใช้ DP: dp[i] = จำนวนวิธีสำหรับ i หลักแรก
        // หรือใช้ greedy counting
        
        // วิธี greedy: เปรียบเทียบทีละหลัก
        for (int i = 0; i < k; i++) {
            int current_digit = n_str[i] - '0';
            
            // นับตัวเลขที่หลัก i น้อยกว่า current_digit
            int less_count = 0;
            for (int digit : digit_vals) {
                if (digit < current_digit) {
                    less_count++;
                } else {
                    break;
                }
            }
            
            result += less_count * pow(d, k - i - 1); // กรณีเลขหลักปัจจุบันมีค่า < หลักใน n
            
            // ตรวจสอบว่ามี digit เท่ากับ current_digit หรือไม่
            bool has_equal = false;
            for (int digit : digit_vals) {
                if (digit == current_digit) {
                    has_equal = true;
                    break;
                }
            }
            
            if (!has_equal) {
                // ถ้าไม่มี digit เท่ากับ current_digit
                // ไม่สามารถสร้างตัวเลขที่มี prefix เหมือน n ได้ต่อ(ไม่จำเป็นต้องคิดต่อ)
                return result;
            }
            
            // ถ้า i เป็นหลักสุดท้าย และมี digit เท่ากับ current_digit
            // ให้บวก 1 (สำหรับตัวเลขที่เท่ากับ n)
            if (i == k - 1) {
                result += 1;
            }
        }
        
        return result;
    }
};