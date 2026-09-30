class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1; // "1", "12", "122" มี '1' เพียงตัวเดียว

        vector<int> s;
        s.reserve(n + 2);
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);

        int read = 2;
        int count1 = 1; // เริ่มต้นนับ '1' ตัวแรกที่ index 0

        while (s.size() < n) {
            int count = s[read++];
            int val = 3 - s.back(); // สลับระหว่าง 1 กับ 2

            while (count-- > 0 && s.size() < n) {
                s.push_back(val);
                if (val == 1) {
                    count1++;
                }
            }
        }

        return count1;
    }
};