class Solution {
private:
    bool isSubsequence(const string& word, const string& s) {
        int i = 0;
        for (char c : s) {
            if (i < word.size() && word[i] == c) {
                i++;
            }
        }
        return i == word.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // เรียงตามความยาวจากมากไปน้อย และตามลำดับพจนานุกรม
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });
        
        for (const string& word : dictionary) {
            if (isSubsequence(word, s)) {
                return word;
            }
        }
        
        return "";
    }
};