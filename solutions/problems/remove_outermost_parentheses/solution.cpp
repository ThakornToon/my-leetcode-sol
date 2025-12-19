class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {  // ไม่ใช่ outermost '('
                    result += c;
                }
                balance++;
            } else {  // c == ')'
                balance--;
                if (balance > 0) {  // ไม่ใช่ outermost ')'
                    result += c;
                }
            }
        }
        
        return result;
    }
};