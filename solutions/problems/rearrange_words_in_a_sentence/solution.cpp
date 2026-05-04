class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string word;
        int idx = 0;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        stable_sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
            return a.length() < b.length();
        });
        
        string result;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            
            if (i == 0) {
                w[0] = toupper(w[0]);
                for (int j = 1; j < w.length(); j++) {
                    w[j] = tolower(w[j]);
                }
            } else {
                for (char& c : w) {
                    c = tolower(c);
                }
            }
            
            if (i > 0) result += " ";
            result += w;
        }
        
        return result;
    }
};