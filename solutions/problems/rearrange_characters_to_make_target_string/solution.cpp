class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        // นับความถี่ตัวอักษรใน s
        vector<int> countS(26, 0);
        for (char c : s) {
            countS[c - 'a']++;
        }
        
        // นับความถี่ตัวอักษรใน target
        vector<int> countTarget(26, 0);
        for (char c : target) {
            countTarget[c - 'a']++;
        }
        
        // หาว่าสามารถสร้าง target ได้มากที่สุดกี่ครั้ง
        int maxCopies = INT_MAX;
        
        for (int i = 0; i < 26; i++) {
            if (countTarget[i] > 0) {                
                // จำนวนครั้งที่สามารถสร้างได้จากตัวอักษรนี้
                int copies = countS[i] / countTarget[i];
                maxCopies = min(maxCopies, copies);
            }
        }
        
        return maxCopies;
    }
};