typedef unsigned long long ull;

// ฟังก์ชันแปลง unsigned long long เป็นสตริง
char* ull_to_str(ull num) {
    char* str = (char*)malloc(21 * sizeof(char)); // ใหญ่พอสำหรับ 2^64
    sprintf(str, "%llu", num);
    return str;
}

char* smallestGoodBase(char* n) {
    ull num = strtoull(n, NULL, 10);
    
    // หาค่า m สูงสุดที่เป็นไปได้
    int max_m = log2(num) + 1;
    
    for (int m = max_m; m >= 1; m--) {
        // Binary search หาค่า k
        ull left = 2;
        ull right = (ull)(pow(num, 1.0/m)) + 1;
        
        while (left <= right) {
            ull mid = left + (right - left) / 2;
            ull sum = 0;
            ull curr = 1;
            int overflow = 0;
            
            // คำนวณผลรวม 1 + k + k^2 + ... + k^m
            for (int i = 0; i <= m; i++) {
                // ตรวจสอบ overflow ก่อนบวก
                if (sum > num - curr || sum > num) {
                    overflow = 1;
                    break;
                }
                sum += curr;
                
                // ตรวจสอบ overflow ก่อนคูณ (สำหรับเทอมถัดไป)
                if (i < m) {
                    if (curr > num / mid) {
                        overflow = 1;
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
                return ull_to_str(mid);
            }
        }
    }
    
    // กรณีพื้นฐานเมื่อ m = 1 (n = 11 ในฐาน n-1)
    return ull_to_str(num - 1);
}