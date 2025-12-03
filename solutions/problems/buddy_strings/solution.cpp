class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        if (s == goal) {
            // ตรวจสอบ duplicate ด้วย array
            int seen[26] = {0};
            for (char c : s) {
                if (seen[c - 'a']++ > 0) return true;
            }
            return false;
        }
        
        int diff = 0;
        int first = -1, second = -1;
        int count[26] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[goal[i] - 'a']--;
            
            if (s[i] != goal[i]) {
                diff++;
                if (diff == 1) first = i;
                else if (diff == 2) second = i;
                else return false;
            }
        }
        
        // ตรวจสอบว่าแต่ละตัวอักษรมีจำนวนเท่ากัน
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        // ถ้ามี 2 ตำแหน่งต่างกัน ต้อง swap ได้
        return diff == 2 && s[first] == goal[second] && s[second] == goal[first];
    }
};