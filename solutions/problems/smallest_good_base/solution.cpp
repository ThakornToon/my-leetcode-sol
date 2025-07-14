class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoull(n);
        
        // ตรวจสอบค่า m ที่เป็นไปได้จากมากไปน้อย
        for (int m = log2(num) + 1; m >= 1; m--) {
            // Binary search หาค่า k
            unsigned long long left = 2;
            unsigned long long right = pow(num, 1.0/m) + 1;
            // n = 1 + k + k² + ... + kᵐ รู้ว่า kᵐ ≤ n เพราะว่า kᵐ เป็นเทอมที่ใหญ่ที่สุดในผลรวม ดังนั้น k ≤ n^(1/m) บวก 1 เพิ่มเพื่อให้แน่ใจว่าไม่พลาดค่าที่เป็นไปได้จากการปัดเศษ เช่น กรณี pow = 3.99999... เนื่องจาก error เล็กน้อยในการคำนวณ
            
            while (left <= right) {
                unsigned long long mid = left + (right - left) / 2;
                unsigned long long sum = 0;
                unsigned long long curr = 1;
                bool overflow = false;
                
                // คำนวณ 1 + k + k^2 + ... + k^m
                for (int i = 0; i <= m; i++) {
                    // ตรวจสอบ overflow ก่อนคำนวณ
                    if (sum > num - curr) { // เทียบเท่ากับ sum + curr > num
                        overflow = true;
                        break;
                    }
                    sum += curr;
                    if (i < m) {
                        if (curr > num / mid) { // ตรวจสอบ overflow
                            overflow = true;
                            break;
                        }
                        curr *= mid;
                    }
                }
                
                if (overflow) {
                    right = mid - 1;
                } else if (sum < num) {
                    left = mid + 1;
                } else {
                    return to_string(mid);
                }
            }
        }
        
        return to_string(num - 1);
    }
};