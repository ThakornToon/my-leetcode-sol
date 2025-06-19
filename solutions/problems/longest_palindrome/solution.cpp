class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char_counts;
        
        // นับความถี่ของแต่ละตัวอักษร
        for (char c : s) {
            char_counts[c]++;
        }
        
        int length = 0;
        bool has_odd = false;
        
        // คำนวณความยาวพาลินโดรม
        for (auto& pair : char_counts) {
            if (pair.second % 2 == 0) {
                length += pair.second;
            } else {
                length += pair.second - 1;
                has_odd = true;
            }
        }
        
        // เพิ่ม 1 ถ้ามีตัวอักษรที่ปรากฏจำนวนคี่ครั้ง
        return has_odd ? length + 1 : length;
    }
};