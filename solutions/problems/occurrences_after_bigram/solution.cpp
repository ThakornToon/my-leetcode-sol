class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        vector<string> result;
        
        // Split text into words
        stringstream ss(text);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Find occurrences
        for (int i = 0; i < (int)words.size() - 2; i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }
        
        return result;
    }
};