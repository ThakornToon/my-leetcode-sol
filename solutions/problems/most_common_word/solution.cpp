class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // แปลง paragraph ให้เป็นตัวเล็กและแทนที่เครื่องหมายด้วยช่องว่าง
        string cleanText = "";
        for (char c : paragraph) {
            if (isalpha(c)) {
                cleanText += tolower(c);
            } else {
                cleanText += ' ';
            }
        }
        
        // แยกคำด้วยตัวเอง
        unordered_map<string, int> count;
        string word = "";
        
        for (char c : cleanText) {
            if (c != ' ') {
                word += c;
            } else {
                if (!word.empty()) {
                    count[word]++;
                    word = "";
                }
            }
        }
        
        // ตรวจสอบคำสุดท้าย
        if (!word.empty()) {
            count[word]++;
        }
        
        // ลบคำต้องห้าม
        for (string badWord : banned) {
            count.erase(badWord);
        }
        
        // หาคำที่พบบ่อยที่สุด
        string result;
        int maxCount = 0;
        for (auto& pair : count) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                result = pair.first;
            }
        }
        
        return result;
    }
};