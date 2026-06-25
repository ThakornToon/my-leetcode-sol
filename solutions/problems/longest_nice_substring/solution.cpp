class Solution {
private:
    bool isNice(const string& s, int start, int end) {
        int upper = 0, lower = 0; // ใช้ bitmask แทน array
        
        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                lower |= (1 << (c - 'a'));
            } else if (c >= 'A' && c <= 'Z') {
                upper |= (1 << (c - 'A'));
            }
        }
        
        return upper == lower;
    }
    
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string result = "";
        
        // เรียงจากยาวไปสั้น เพื่อหาเจอตัวแรกก็จบได้
        for (int len = n; len >= 2; len--) {
            for (int i = 0; i + len <= n; i++) {
                if (isNice(s, i, i + len - 1)) {
                    return s.substr(i, len);
                }
            }
        }
        
        return "";
    }
};