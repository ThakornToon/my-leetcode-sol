class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxWin = 0;
        int mostChar = 0;
        std::vector<int> ch(26, 0);
        int len = s.length();
        
        for (int right = 0; right < len; ++right) {
            char c = s[right] - 'A';
            ch[c]++;
            mostChar = max(mostChar, ch[c]); // นับจำนวนตัวอักษรที่ซ้ำมากที่สุด โดยหากมีการลบไม่จำเป็นต้องหาใหม่เพราะขนาดหน้าต่างเราจะเท่าเดิม หากจะได้ขนาดหน้าต่างที่มากขึ้นต้องมี mostChar ที่มากขึ้นด้วย
            
            while (right - left + 1 - mostChar > k) {
                ch[s[left] - 'A']--;
                left++;
            }
            
            maxWin = max(maxWin, right - left + 1);
        }
        
        return maxWin;
    }
};