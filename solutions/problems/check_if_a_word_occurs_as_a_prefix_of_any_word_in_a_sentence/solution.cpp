class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1;
        
        while (ss >> word) {
            if (word.find(searchWord) == 0) {  // prefix check
                return index;
            }
            index++;
        }
        
        return -1;
    }
};