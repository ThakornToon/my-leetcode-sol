class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;  // จำนวน ')' ที่ต้องเพิ่มทางซ้าย
        int right = 0; // จำนวน '(' ที่ต้องเพิ่มทางขวา
        
        for (char c : s) {
            if (c == '(') {
                // ต้องการ ')' ในภายหลัง
                right++;
            } else if (c == ')') {
                if (right > 0) {
                    // มี '(' รออยู่ ให้คู่กัน
                    right--;
                } else {
                    // ต้องเพิ่ม '(' ทางซ้าย
                    left++;
                }
            }
        }
        
        return left + right;
    }
};