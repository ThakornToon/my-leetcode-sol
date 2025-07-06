class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if (len == 1) {
            return false;
        }

        for (int i = 1; i <= len / 2; i++) {
            if (len % i != 0) {
                continue;
            }
            
            string pattern = s.substr(0, i);
            bool match = true;

            for (int j = i; j <= len - i; j += i) {
                if (s.substr(j, i) != pattern) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return true;
            }
        }

        return false;
    }
};