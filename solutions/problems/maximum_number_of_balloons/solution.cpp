class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // นับความถี่ของตัวอักษรใน text
        unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }
        
        // สำหรับ "balloon" ต้องการ:
        // b: 1, a: 1, l: 2, o: 2, n: 1
        // หาค่าน้อยที่สุดที่สามารถสร้างได้
        
        // วิธีที่ 1: หาโดยตรง
        int b_count = freq['b'];
        int a_count = freq['a'];
        int l_count = freq['l'] / 2;    // ต้องการ 2 ตัวต่อคำ
        int o_count = freq['o'] / 2;    // ต้องการ 2 ตัวต่อคำ
        int n_count = freq['n'];
        
        return min({b_count, a_count, l_count, o_count, n_count});
    }
};