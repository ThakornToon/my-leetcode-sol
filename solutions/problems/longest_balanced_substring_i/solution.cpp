class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                // หาความถี่ของตัวแรกที่พบ
                int target_freq = -1;
                bool balanced = true;
                
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        if (target_freq == -1) {
                            target_freq = freq[c];
                        } else if (freq[c] != target_freq) {
                            balanced = false;
                            break;
                        }
                    }
                }
                
                if (balanced) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};