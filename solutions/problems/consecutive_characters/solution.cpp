class Solution {
public:
    int maxPower(string s) {
        int maxLen = 0;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            maxLen = max(maxLen, j - i);
            i = j;
        }
        
        return maxLen;
    }
};