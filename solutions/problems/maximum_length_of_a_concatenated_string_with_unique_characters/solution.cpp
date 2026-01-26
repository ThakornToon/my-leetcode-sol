class Solution {
public:
    int maxLength(vector<string>& arr) {
vector<int> masks;
        vector<int> lengths;
        
        // 1. แปลงสตริงเป็น masks
        for (const string& s : arr) {
            int mask = 0;
            bool valid = true;
            
            for (char c : s) {
                int bit = 1 << (c - 'a');
                
                // ตรวจสอบตัวอักษรซ้ำในสตริงเดียวกัน
                if (mask & bit) {
                    valid = false;
                    break;
                }
                
                mask |= bit;
            }
            
            if (valid) {
                masks.push_back(mask);
                lengths.push_back(s.length());
            }
        }
        
        // 2. ใช้ backtracking
        int maxLen = 0;
        backtrack(masks, lengths, 0, 0, 0, maxLen);
        
        return maxLen;
    }
    
private:
    void backtrack(const vector<int>& masks, const vector<int>& lengths, 
                   int index, int currentMask, int currentLength, int& maxLen) {
        // อัปเดตค่าสูงสุด
        if (currentLength > maxLen) {
            maxLen = currentLength;
        }
        
        // ฐาน: ตรวจสอบครบทุกสตริงแล้ว
        if (index == masks.size()) {
            return;
        }
        
        // 1. ไม่เลือกสตริงนี้
        backtrack(masks, lengths, index + 1, currentMask, currentLength, maxLen);
        
        // 2. เลือกสตริงนี้ (ถ้าไม่ชนกับ masks ที่มีอยู่)
        if ((currentMask & masks[index]) == 0) {
            backtrack(masks, lengths, index + 1, 
                     currentMask | masks[index], 
                     currentLength + lengths[index], 
                     maxLen);
        }
    }
};