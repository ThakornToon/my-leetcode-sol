class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length = 0;  // ความยาวของ decoded string
        
        // Step 1: คำนวณ total length
        for (char c : s) {
            if (isdigit(c)) {
                length *= (c - '0');
            } else {
                length++;
            }
        }
        // Step 2: หา character ที่ตำแหน่ง k โดยเดินจากหลัง
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            
            // ถ้า k == 0 ให้ k = length (ตำแหน่งสุดท้ายของ segment ปัจจุบัน)
            if (k == 0 && isalpha(c)) {
                return string(1, c);
            }
            
            if (isdigit(c)) {
                int d = c - '0';
                length /= d;  // ย้อนกลับไปก่อน repeat
                k %= length;  // ปรับ k ให้อยู่ใน segment ก่อน repeat
                // ถ้า k == 0 หมายถึงตำแหน่งสุดท้ายของ segment ก่อน repeat
                if (k == 0) k = length;
            } else {
                if (k == length) {
                    return string(1, c);
                }
                length--;
            }
        }
        
        return "";   
    }
};