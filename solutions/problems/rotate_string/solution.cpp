class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s.empty()) {
            return true;
        }
        
        int n = s.length();
        for (int i = 0; i < n; i++) { // ให้ตำแหน่ง i เป็นตัวเริ่มต้นเมื่อลองหมุน
            bool match = true;
            for (int j = 0; j < n; j++) { // เทียบทีละตัวว่าจะได้ไหม
                if (s[(i + j) % n] != goal[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
        
        return false;
    }
};