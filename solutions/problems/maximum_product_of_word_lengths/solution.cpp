class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0);
        
        // สร้าง bitmask สำหรับแต่ละคำ
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
        }
        
        int max_prod = 0;
        // เปรียบเทียบทุกคู่ของคำ
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((masks[i] & masks[j]) == 0) { // ไม่มีตัวอักษรร่วมกัน
                    max_prod = max(max_prod, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return max_prod;
    }
};