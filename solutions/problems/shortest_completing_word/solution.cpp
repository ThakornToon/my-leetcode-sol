class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // Build frequency map from licensePlate
        vector<int> licenseCount(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) {
                licenseCount[tolower(c) - 'a']++;
            }
        }
        
        string result;
        for (string& word : words) {
            // Build frequency map for current word
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }
            
            // Check if word contains all letters from licensePlate
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] < licenseCount[i]) {
                    valid = false;
                    break;
                }
            }
            
            // Update result if valid and shorter
            if (valid && (result.empty() || word.length() < result.length())) {
                result = word;
            }
        }
        
        return result;

    }
};