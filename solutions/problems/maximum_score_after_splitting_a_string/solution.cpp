class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> prefixZeros(n + 1, 0);
        vector<int> suffixOnes(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixZeros[i + 1] = prefixZeros[i] + (s[i] == '0' ? 1 : 0);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            suffixOnes[i] = suffixOnes[i + 1] + (s[i] == '1' ? 1 : 0);
        }
        
        int maxScore = 0;
        for (int i = 1; i < n; i++) {
            int score = prefixZeros[i] + suffixOnes[i];
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};