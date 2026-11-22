class Solution {
public:
    bool checkString(string s) {
        bool seen_b = false;
        for (char c : s) {
            if (c == 'b') {
                seen_b = true;
            } else if (seen_b) { // c == 'a' และเคยเจอ 'b' มาแล้ว
                return false;
            }
        }
        return true;
    }
};