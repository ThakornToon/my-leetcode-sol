class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> count(26, 0);
        
        // นับจำนวนตัวอักษรทั้งหมด
        for (char c : text) {
            count[c - 'a']++;
        }
        
        int maxLen = 0;
        int i = 0;
        
        while (i < n) {
            int j = i;
            // หาความยาวกลุ่มปัจจุบัน
            while (j < n && text[j] == text[i]) {
                j++;
            }
            
            int curLen = j - i;
            char curChar = text[i];
            
            // กรณี 1: เพิ่ม 1 ตัวจากกลุ่มอื่น
            if (count[curChar - 'a'] > curLen) {
                maxLen = max(maxLen, curLen + 1);
            } else {
                maxLen = max(maxLen, curLen);
            }
            
            // กรณี 2: ตรวจสอบการรวมกลุ่ม
            // ดูว่ามีตัวอักษรอื่นคั่น 1 ตัวหรือไม่
            int k = j + 1;
            if (k < n && text[k] == curChar) {
                // หาความยาวกลุ่มถัดไป
                while (k < n && text[k] == curChar) {
                    k++;
                }
                int nextLen = k - (j + 1);
                int combined = curLen + nextLen;
                
                // มีช่องว่าง 1 ตัวตรงกลาง (ที่ตำแหน่ง j)
                if (count[curChar - 'a'] > combined) {
                    maxLen = max(maxLen, combined + 1);
                } else {
                    maxLen = max(maxLen, combined);
                }
            }
            
            i = j;
        }
        
        return maxLen;
    }
};