class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (std::is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        
        char min_char = s[0], max_char = s[0];
        for (char c : s) {
            min_char = std::min(min_char, c);
            max_char = std::max(max_char, c);
        }
        
        int first_min_idx = -1, last_max_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == min_char && first_min_idx == -1) {
                first_min_idx = i;
            }
            if (s[i] == max_char) {
                last_max_idx = i;
            }
        }
        
        if (first_min_idx == 0 || last_max_idx == n - 1) return 1;
        if (first_min_idx == n - 1 && last_max_idx == 0) return 3;
        
        return 2;
    }
};