class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') count++;
            } else {
                if (s[i] != '1') count++;
            }
        }
        
        return min(count, n - count);
    }
};