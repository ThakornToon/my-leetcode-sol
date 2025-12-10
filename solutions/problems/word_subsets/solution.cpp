class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // สร้าง array สำหรับเก็บความถี่สูงสุดจาก words2
        int maxFreq[26] = {0};
        
        // คำนวณความถี่สูงสุดสำหรับแต่ละตัวอักษรจาก words2
        for (const string& word : words2) {
            int currentFreq[26] = {0};
            for (char c : word) {
                currentFreq[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], currentFreq[i]);
            }
        }
        
        // ตรวจสอบว่า words1 แต่ละคำเป็น universal หรือไม่
        vector<string> result;
        
        for (const string& word : words1) {
            int wordFreq[26] = {0};
            for (char c : word) {
                wordFreq[c - 'a']++;
            }
            
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (wordFreq[i] < maxFreq[i]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};