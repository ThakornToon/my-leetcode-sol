class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> freqA(26, 0), freqB(26, 0);
        for (char c : a) freqA[c-'a']++;
        for (char c : b) freqB[c-'a']++;
        
        // สร้าง prefix sum
        vector<int> prefixA(27, 0), prefixB(27, 0);
        for (int i = 0; i < 26; i++) {
            prefixA[i+1] = prefixA[i] + freqA[i];
            prefixB[i+1] = prefixB[i] + freqB[i];
        }
        
        int ans = INT_MAX;
        int lenA = a.length(), lenB = b.length();
        
        // Condition 1 & 2
        // ให้ตัวอักษรที่ i เป็นจุดแบ่งในการเปลี่ยนตัวอักษรใน a และ b
        for (int i = 0; i < 25; i++) {
            // ลำดับตัวอักษรทุกตัวใน a <= i, b > i
            int changes1 = (lenA - prefixA[i+1]) + prefixB[i+1];
            // ลำดับตัวอักษรทุกตัวใน b <= i, a > i
            int changes2 = (lenB - prefixB[i+1]) + prefixA[i+1];
            ans = min(ans, min(changes1, changes2));
        }
        
        // Condition 3 ให้ทุกตัวเป็นตัวอักษรตัวเดียวกัน
        for (int i = 0; i < 26; i++) {
            ans = min(ans, lenA + lenB - freqA[i] - freqB[i]);
        }
        
        return ans;
    }
};