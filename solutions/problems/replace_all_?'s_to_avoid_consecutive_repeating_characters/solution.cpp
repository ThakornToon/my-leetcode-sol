class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                // ลองใส่ 'a', 'b', 'c'
                for (char c = 'a'; c <= 'c'; c++) {
                    // ตรวจสอบว่าตัวอักษรนี้ซ้ำกับตัวก่อนหน้าหรือถัดไปหรือไม่
                    if ((i > 0 && s[i-1] == c) || 
                        (i < n-1 && s[i+1] == c)) {
                        continue; // ซ้ำ ข้ามไปลองตัวถัดไป
                    }
                    s[i] = c; // ใส่ตัวอักษรที่ใช้ได้
                    break;
                }
            }
        }
        
        return s;
    }
};