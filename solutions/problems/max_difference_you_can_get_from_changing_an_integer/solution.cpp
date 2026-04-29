class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxStr = s, minStr = s;
        
        // Max: find first non-9
        for (char c : s) {
            if (c != '9') {
                replace(maxStr.begin(), maxStr.end(), c, '9');
                break;
            }
        }
        
        // Min: handle first digit
        if (s[0] != '1') {
            replace(minStr.begin(), minStr.end(), s[0], '1');
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != s[0]) {
                    replace(minStr.begin(), minStr.end(), s[i], '0');
                    break;
                }
            }
        }
        
        return stoi(maxStr) - stoi(minStr);
    }
};