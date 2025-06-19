class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return result;
        }
        array<int, 26> pCount = {0};
        array<int, 26> sCount = {0};
        
        // นับความถี่ของตัวอักษรใน p
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        // เริ่ม sliding window
        for (int i = 0; i < s.size(); ++i) {
            // เพิ่มตัวอักษรปัจจุบันใน window
            sCount[s[i] - 'a']++;
            
            // ถ้า window มีขนาดใหญ่เกิน ให้ลบตัวอักษรที่ออกจาก window
            if (i >= p.size()) {
                sCount[s[i - p.size()] - 'a']--;
            }
            
/* 
ใน C++, array มี overloaded operator == ที่เปรียบเทียบทุก element ใน array
การเปรียบเทียบ sCount == pCount จะเป็นจริงก็ต่อเมื่อ:
ทั้งสอง array มีขนาดเดียวกัน (ซึ่งเป็นจริงในกรณีนี้)
ทุก element ในตำแหน่งเดียวกันมีค่าเท่ากัน
*/
            if (sCount == pCount) {
                result.push_back(i - p.size() + 1);
            }
        }
        
        return result;
    }
};