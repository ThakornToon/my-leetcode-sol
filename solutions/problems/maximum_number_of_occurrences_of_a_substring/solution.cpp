class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        unordered_map<string, int> count;
        int maxResult = 0;
        
        // frequency array สำหรับ window ปัจจุบัน
        int freq[26] = {0};
        int unique = 0;
        
        // ตรวจสอบ window แรก
        for (int i = 0; i < minSize; i++) {
            if (freq[s[i] - 'a']++ == 0) unique++;
        }
        
        // ตรวจสอบทุก window ที่เลื่อนไป i 
        // สนใจแค่ความยาว minSize ที่ให้ผลลัพธ์ดีสุด
        for (int i = 0; i <= n - minSize; i++) {
            if (i > 0) {
                // เลื่อน window
                if (--freq[s[i - 1] - 'a'] == 0) unique--;
                if (freq[s[i + minSize - 1] - 'a']++ == 0) unique++;
            }
            
            if (unique <= maxLetters) {
                string substr = s.substr(i, minSize);
                count[substr]++;
                maxResult = max(maxResult, count[substr]);
            }
        }
        
        return maxResult;
    }
};