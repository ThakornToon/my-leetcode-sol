#define MOD 1000000007

int numDecodings(char* s) {
    if (s[0] == '0') return 0;
    int n = strlen(s);
    
    // dp[i-2] คือวิธีถอดรหัสถึงตำแหน่ง i-2
    long long prev_two = 1;  
    // dp[i-1] คือวิธีถอดรหัสถึงตำแหน่ง i-1
    long long prev_one = 0; 
    
    // Base Case: วิธีถอดรหัสถึงตำแหน่ง i=0
    if (s[0] == '*') {
        prev_one = 9;  // '*' สามารถเป็น 1-9 → 9 วิธี
    } else {
        prev_one = 1;  // ตัวเลขปกติ 1 วิธี
    }
    
    // DP Loop เริ่มจากตำแหน่ง i=1
    for (int i = 1; i < n; i++) {
        long long current_ways = 0;  // dp[i]: วิธีถอดรหัสถึงตำแหน่งปัจจุบัน
        
        if (s[i] == '*') {
            // '*' เป็น 1-9 → 9 วิธี 
            // จำนวนวิธี = (วิธีถึง i-1 ทั้งหมด) * 9
            current_ways = (prev_one * 9) % MOD;
        } else if (s[i] != '0') {
            // ตัวเลข 1-9 → 1 วิธี
            // จำนวนวิธี = (วิธีถึง i-1 ทั้งหมด) * 1
            current_ways = prev_one; 
        } else {
            // '0' ไม่สามารถอยู่เดี่ยวได้
            current_ways = 0;
        }
        
        char prev_char = s[i-1];
        long long ways_two_digits = 0;
        
        if (prev_char == '*') {
            if (s[i] == '*') {
                // ** สามารถเป็น 11-19 (9) และ 21-26 (6) → 15 วิธี
                ways_two_digits = 15;
            } else if (s[i] >= '0' && s[i] <= '6') {
                // *X เมื่อ X=0-6: * สามารถเป็น 1 หรือ 2 → 2 วิธี
                ways_two_digits = 2;
            } else {
                // *X เมื่อ X=7-9: * ต้องเป็น 1 เท่านั้น → 1 วิธี
                ways_two_digits = 1;
            }
        } else if (prev_char == '1') {
            if (s[i] == '*') {
                // 1* สามารถเป็น 11-19 → 9 วิธี
                ways_two_digits = 9;
            } else {
                // 1X เมื่อ X=0-9 → 1 วิธี
                ways_two_digits = 1;
            }
        } else if (prev_char == '2') {
            if (s[i] == '*') {
                // 2* สามารถเป็น 21-26 → 6 วิธี
                ways_two_digits = 6;
            } else if (s[i] >= '0' && s[i] <= '6') {
                // 2X เมื่อ X=0-6 → 1 วิธี
                ways_two_digits = 1;
            } else {
                ways_two_digits = 0;  // 27-29 ไม่มี
            }
        } else {
            ways_two_digits = 0; // ตัวก่อนหน้าเป็น 0,3-9 ไม่สามารถสร้าง two-digit ได้
        }
        
        // เพิ่มวิธีถอดรหัสแบบ 2 หลัก โดยคูณกับวิธีถอดรหัสถึงตำแหน่ง i-2
        current_ways = (current_ways + (prev_two * ways_two_digits) % MOD) % MOD;
        
        prev_two = prev_one;
        prev_one = current_ways;
    }
    
    return (int)prev_one; // prev_one ตอนนี้คือ dp[n-1] ซึ่งเป็นผลลัพธ์สุดท้าย
}