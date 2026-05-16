class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        
        // เก็บตำแหน่งจากซ้ายไปขวา
        for (int i = 0; i < s.size(); i++) {
            pos[s[i]-'0'].push(i);
        }
        
        for (char c : t) {
            int digit = c - '0';
            
            if (pos[digit].empty()) return false;
            
            // เอาตัวที่อยู่ซ้ายสุด (แต่ conceptual คือขวาสุดของที่เหลือ)
            int currentPos = pos[digit].front();
            
            // ตรวจสอบตัวเลขที่น้อยกว่า
            for (int smaller = 0; smaller < digit; smaller++) {
                if (!pos[smaller].empty() && pos[smaller].front() < currentPos) {
                    return false;
                }
            }
            
            pos[digit].pop();
        }
        
        return true;
    }
};