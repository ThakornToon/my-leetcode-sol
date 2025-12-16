class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if (bound < 2) return {};
        
        unordered_set<int> result_set;
        
        // สร้างลิสต์ของ x^i
        vector<long long> x_powers;
        if (x == 1) {
            x_powers.push_back(1);
        } else {
            for (long long i = 1; i <= bound; i *= x) {
                x_powers.push_back(i);
            }
        }
        
        // สร้างลิสต์ของ y^j
        vector<long long> y_powers;
        if (y == 1) {
            y_powers.push_back(1);
        } else {
            for (long long j = 1; j <= bound; j *= y) {
                y_powers.push_back(j);
            }
        }
        
        // ทดสอบทุกคู่
        for (long long a : x_powers) {
            for (long long b : y_powers) {
                long long sum = a + b;
                if (sum <= bound) {
                    result_set.insert((int)sum);
                } else {
                    // ถ้า b ใหญ่เกิน bound - a แล้ว break
                    break;
                }
            }
        }
        
        // แปลงเป็น vector และเรียงลำดับ
        vector<int> result(result_set.begin(), result_set.end());
        sort(result.begin(), result.end());
        
        return result;
    }
};