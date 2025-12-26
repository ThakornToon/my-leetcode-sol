class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // นับความถี่ตัวอักษรใน chars
        int charCount[26] = {0};
        for (char c : chars) {
            charCount[c - 'a']++;
        }
        
        int totalLength = 0;
        
        for (const string& word : words) {
            // สำเนา charCount
            int tempCount[26];
            copy(begin(charCount), end(charCount), begin(tempCount));
            
            bool canForm = true;
            for (char c : word) {
                if (--tempCount[c - 'a'] < 0) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                totalLength += word.size();
            }
        }
        
        return totalLength;
    }
};