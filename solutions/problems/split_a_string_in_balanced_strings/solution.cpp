class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;  // +1 สำหรับ 'L', -1 สำหรับ 'R' (หรือสลับกันก็ได้)
        int count = 0;
        
        for (char c : s) {
            if (c == 'L') {
                balance++;
            } else {  // c == 'R'
                balance--;
            }
            
            // เมื่อ balance เป็น 0 แสดงว่าเจอ balanced substring
            if (balance == 0) {
                count++;
            }
        }
        
        return count;
    }
};