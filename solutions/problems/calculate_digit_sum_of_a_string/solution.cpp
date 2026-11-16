class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";
            for (size_t i = 0; i < s.length(); i += k) {
                int sum = 0;
                // บวกตัวเลขในกลุ่มปัจจุบันที่มีความยาวไม่เกิน k
                for (size_t j = i; j < i + k && j < s.length(); ++j) {
                    sum += s[j] - '0';
                }
                next_s += to_string(sum);
            }
            s = next_s;
        }
        return s;
    }
};