class Solution {
public:
    string reorderSpaces(string text) {
        // นับจำนวนช่องว่าง
        int spaceCount = 0;
        for (char c : text) {
            if (c == ' ') spaceCount++;
        }
        
        // แยกคำโดยใช้ stringstream
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        int wordCount = words.size();
        
        // ถ้าไม่มีคำ หรือมีคำเดียว
        if (wordCount <= 1) {
            string result = "";
            if (wordCount == 1) result = words[0];
            result += string(spaceCount, ' ');
            return result;
        }
        
        // คำนวณช่องว่างระหว่างคำและเศษ
        int spacesBetween = spaceCount / (wordCount - 1);
        int extraSpaces = spaceCount % (wordCount - 1);
        
        // สร้างผลลัพธ์
        string result = words[0];
        for (int i = 1; i < wordCount; i++) {
            result += string(spacesBetween, ' ') + words[i];
        }
        result += string(extraSpaces, ' ');
        
        return result;
    }
};