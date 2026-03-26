class Solution {
public:
    vector<string> printVertically(string s) {
        // แยกคำ
        vector<string> words;
        stringstream ss(s);
        string word;
        int maxLen = 0;
        
        while (ss >> word) {
            words.push_back(word);
            maxLen = max(maxLen, (int)word.length());
        }
        
        vector<string> result;
        
        // สร้าง string แนวตั้ง
        for (int j = 0; j < maxLen; j++) {
            string col;
            for (int i = 0; i < words.size(); i++) {
                if (j < words[i].length()) {
                    col += words[i][j];
                } else {
                    col += ' ';
                }
            }
            
            // ตัดช่องว่างท้าย
            while (!col.empty() && col.back() == ' ') {
                col.pop_back();
            }
            
            result.push_back(col);
        }
        
        return result;
    }
};