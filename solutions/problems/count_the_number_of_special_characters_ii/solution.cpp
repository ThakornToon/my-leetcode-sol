class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } else if (isupper(c)) {
                int idx = c - 'A';
                if (firstUpper[idx] == INT_MAX) {
                    firstUpper[idx] = i;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX && 
                lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
        
        return count;
    }
};