class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        vector<string> words;
        int start = 0;
        int end = s.find(' ');
        // ค้นหาตำแหน่งของช่องว่างแรกใน string s
        // find() จะคืนค่า string::npos ถ้าไม่พบช่องว่าง
        while (end != string::npos) {
            words.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(' ', start);
        }
        words.push_back(s.substr(start));
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string& word = words[i];
            
            if (charToWord.count(c)) {
                if (charToWord[c] != word) {
                    return false;
                }
            } else {
                if (wordToChar.count(word)) {
                    return false;
                }
                charToWord[c] = word;
                wordToChar[word] = c;
            }
        }
        
        return true;
    }
};