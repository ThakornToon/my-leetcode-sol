class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        
        int count = 0;
        backtrack(count, freq);
        return count;
    }

    void backtrack(int& count, vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Use this character
                count++;
                freq[i]--;
                
                // Recurse
                backtrack(count, freq);
                
                // Backtrack
                freq[i]++;
            }
        }
    }
};