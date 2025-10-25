class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        int n = sentence.size();
        int wordCount = 1;
        string word = "";
        
        for (int i = 0; i <= n; i++) {
            if (i == n || sentence[i] == ' ') {
                if (!word.empty()) {
                    // แปลงคำ
                    char c = tolower(word[0]);
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                        ans += word + "ma";
                    } else {
                        ans += word.substr(1) + word[0] + "ma";
                    }
                    
                    // เพิ่ม a ตามจำนวน
                    for (int j = 0; j < wordCount; j++) {
                        ans += 'a';
                    }
                    
                    // เพิ่มช่องว่าง
                    if (i != n) ans += ' ';
                    
                    wordCount++;
                    word = "";
                }
            } else {
                word += sentence[i];
            }
        }
        
        return ans;
    }
};