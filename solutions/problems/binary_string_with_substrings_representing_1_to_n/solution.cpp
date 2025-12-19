class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> found;
        
        // สกัดทุก substring ที่เป็นไปได้จาก s
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue; // ละ leading zero
            
            int num = 0;
            for (int j = i; j < len; j++) {
                num = (num << 1) + (s[j] - '0');
                
                if (num > n) break; // ใหญ่กว่า n ไม่สนใจ
                if (num >= 1 && num <= n) {
                    found.insert(num);
                }
            }
        }
        
        // ตรวจสอบว่าพบทุกจำนวนจาก 1 ถึง n หรือไม่
        return found.size() == n;
    }
};