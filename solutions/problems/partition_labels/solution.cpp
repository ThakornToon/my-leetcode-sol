class Solution {
public:
    vector<int> partitionLabels(string s) {
        // บันทึกตำแหน่งสุดท้ายของแต่ละตัวอักษร
        int last[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0;  // จุดเริ่มต้นของส่วนปัจจุบัน
        int end = 0;    // จุดสิ้นสุดของส่วนปัจจุบัน
        
        for (int i = 0; i < s.length(); i++) {
            // ขยายขอบเขตให้ครอบคลุมตำแหน่งสุดท้ายของตัวอักษรนี้
            end = max(end, last[s[i] - 'a']);
            
            // ถ้าถึงจุดสิ้นสุดของส่วนปัจจุบัน
            if (i == end) {
                result.push_back(end - start + 1);  // บันทึกความยาว
                start = i + 1;  // เริ่มส่วนใหม่
            }
        }
        
        return result;
    }
};