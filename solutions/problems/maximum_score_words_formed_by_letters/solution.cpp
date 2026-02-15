class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> available(26, 0);
        for (char c : letters) {
            available[c - 'a']++;
        }
        
        return dfsMemo(words, 0, available, score);
    }

private:
    int dfsMemo(const vector<string>& words, int index, vector<int>& freq, const vector<int>& score) {
        if (index == words.size()) {
            return 0;
        }
        
        // Option 1: ไม่เลือกคำนี้
        int maxScore = dfsMemo(words, index + 1, freq, score);
        
        // Option 2: เลือกคำนี้ (ถ้าสามารถใช้ได้)        
        // ตรวจสอบว่ามีตัวอักษรพอ
        vector<int> wordFreq(26, 0);
        for (char c : words[index]) {
            wordFreq[c - 'a']++;
        }
        
        bool canUse = true;
        for (int i = 0; i < 26; i++) {
            if (wordFreq[i] > freq[i]) {
                canUse = false;
                break;
            }
        }
        
        if (canUse) {
            // ใช้คำ
            for (char c : words[index]) {
                freq[c - 'a']--;
            }
            
            // คำนวณคะแนน
            int wordScore = 0;
            for (char c : words[index]) {
                wordScore += score[c - 'a'];
            }
            
            // DFS ต่อ
            maxScore = max(maxScore,  wordScore + dfsMemo(words, index + 1, freq, score));
            
            // คืนคำ
            for (char c : words[index]) {
                freq[c - 'a']++;
            }
        }
        
        return maxScore;
    }
};