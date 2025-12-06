class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for (const string& word : words) {
            if (matchesPattern(word, pattern)) {
                result.push_back(word);
            }
        }
    
        return result;
    }
private:
    bool matchesPattern(const string& word, const string& pattern) {
        if (word.length() != pattern.length()) return false;
        
        unordered_map<char, char> patternToWord;
        unordered_map<char, char> wordToPattern;
        
        for (int i = 0; i < word.length(); i++) {
            char p = pattern[i];
            char w = word[i];
            
            // ตรวจสอบ mapping จาก pattern ไป word
            if (patternToWord.find(p) != patternToWord.end()) {
                if (patternToWord[p] != w) return false;
            } else {
                patternToWord[p] = w;
            }
            
            // ตรวจสอบ mapping จาก word ไป pattern
            if (wordToPattern.find(w) != wordToPattern.end()) {
                if (wordToPattern[w] != p) return false;
            } else {
                wordToPattern[w] = p;
            }
        }
        
        return true;
    }
};