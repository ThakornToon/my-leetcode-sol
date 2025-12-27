class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();        
        int i = 0;  // candidate 1
        int j = 1;  // candidate 2
        int k = 0;  // length compared
        
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                k++;
                continue;
            }
            
            if (s[i + k] < s[j + k]) {
                // candidate j is better
                // i ต้องกระโดดอย่างน้อย k+1 หรือ j
                // fedfedgg -> fedf fedg
                // efg
                i = max(i + k + 1, j);
                j = i + 1;
            } else {
                // candidate i is better การบวก k จะข้ามส่วนที่ซ้ำเพื่อไม่ให้คิดซ้ำซ้อน
                // bbbbaceddddf -> bbbb bbba
                // fedfedaa -> fedf feda
                j = j + k + 1;
            }
            k = 0;
        }
        
        return s.substr(i);
    }
};