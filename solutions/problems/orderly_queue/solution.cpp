class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            // หา rotation ที่น้อยที่สุด
            string ans = s;
            string doubled = s + s;
            
            for (int i = 1; i < s.length(); i++) {
                string candidate = doubled.substr(i, s.length());
                if (candidate < ans) {
                    ans = candidate;
                }
            }
            return ans;
        } else {
            // k >= 2: เรียงลำดับได้เสมอ
            sort(s.begin(), s.end());
            return s;
        }
    }
};