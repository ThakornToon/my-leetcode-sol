class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int n = s.length();
        
        // นับความถี่
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // หาตัวอักษรที่มีความถี่สูงสุด
        int maxCount = 0, maxChar = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxChar = i;
            }
        }
        
        // ตรวจสอบความเป็นไปได้
        if (maxCount > (n + 1) / 2) {
            return "";
        }
        
        string result(n, ' ');
        int index = 0;
        
        // ใส่ตัวอักษรที่มีความถี่สูงสุดก่อนในตำแหน่งคู่
        while (count[maxChar] > 0) {
            result[index] = 'a' + maxChar;
            index += 2;
            count[maxChar]--;
        }
        
        // ใส่ตัวอักษรที่เหลือ
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                if (index >= n) index = 1;  // กลับมาใส่ตำแหน่งคี่
                result[index] = 'a' + i;
                index += 2;
                count[i]--;
            }
        }
        
        return result;
    }
};