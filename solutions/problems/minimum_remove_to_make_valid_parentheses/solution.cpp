class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // First pass: remove invalid ')'
        string temp;
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                balance++;
                temp += c;
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                    temp += c;
                }
                // ถ้า balance <= 0 ไม่เพิ่ม ')' นี้
            } else {
                temp += c;
            }
        }
        
        // Second pass: remove invalid '(' (from right to left)
        string result;
        balance = 0;
        
        // วนจากขวาไปซ้าย
        for (int i = temp.length() - 1; i >= 0; i--) {
            char c = temp[i];
            if (c == ')') {
                balance++;
                result += c;
            } else if (c == '(') {
                if (balance > 0) {
                    balance--;
                    result += c;
                }
                // ถ้า balance <= 0 ไม่เพิ่ม '(' นี้
            } else {
                result += c;
            }
        }
        
        // Reverse เพราะสร้างจากขวาไปซ้าย
        reverse(result.begin(), result.end());
        
        return result;
    }
};