class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        
        for (char c : word) {
            if (islower(c)) {
                lower[c - 'a']++;
            } else if (isupper(c)) {
                upper[c - 'A']++;
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] > 0 && upper[i] > 0) {
                count++;
            }
        }
        
        return count;
    }
};