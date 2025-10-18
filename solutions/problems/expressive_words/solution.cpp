class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for (const string& word : words) {
            if (isExpressive(s, word)) {
                count++;
            }
        }
        return count;
    }
    
private:
    bool isExpressive(const string& s, const string& word) {
        int i = 0, j = 0;
        int n = s.size(), m = word.size();
        
        while (i < n && j < m) {
            if (s[i] != word[j]) return false;
            
            // นับกลุ่มใน s
            int s_count = 0;
            char s_char = s[i];
            while (i < n && s[i] == s_char) {
                s_count++;
                i++;
            }
            
            // นับกลุ่มใน word  
            int w_count = 0;
            char w_char = word[j];
            while (j < m && word[j] == w_char) {
                w_count++;
                j++;
            }
            
            // ตรวจสอบกฎ
            if (s_count < w_count) return false;
            if (s_count < 3 && s_count != w_count) return false;
        }
        
        return i == n && j == m;
    }
};