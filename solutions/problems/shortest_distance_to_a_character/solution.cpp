class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> result(n, INT_MAX);
        
        // Pass 1: Left to Right
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                prev = i;
            }
            if (prev != -1) {
                result[i] = min(result[i], i - prev);
            }
        }
        
        // Pass 2: Right to Left
        prev = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                prev = i;
            }
            if (prev != -1) {
                result[i] = min(result[i], prev - i);
            }
        }
        
        return result;
    }
};