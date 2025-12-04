class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // แปลง n เป็น string sorted
        string nStr = to_string(n);
        sort(nStr.begin(), nStr.end());
        
        // สร้าง list ของ power of 2 (sorted string)
        for (int i = 0; i < 31; i++) {  // 2^30 ≈ 1e9
            long long power = 1LL << i;  // 2^i
            string powerStr = to_string(power);
            sort(powerStr.begin(), powerStr.end());
            
            if (nStr == powerStr) {
                return true;
            }
        }
        
        return false;
    }
};