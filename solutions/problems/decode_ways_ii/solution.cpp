class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length();
        const int MOD = 1000000007;
        
        long long prev_two = 1;
        long long prev_one = 0;
        
        // Base case for first character
        if (s[0] == '*') {
            prev_one = 9;
        } else {
            prev_one = 1;
        }
        
        for (int i = 1; i < n; i++) {
            long long current_ways = 0;
            
            // Single digit decoding
            if (s[i] == '*') {
                current_ways = (prev_one * 9) % MOD;
            } else if (s[i] != '0') {
                current_ways = prev_one;
            } else {
                current_ways = 0;
            }
            
            // Two digit decoding
            char prev_char = s[i - 1];
            long long ways_two_digits = 0;
            
            if (prev_char == '*') {
                if (s[i] == '*') {
                    ways_two_digits = 15;
                } else if (s[i] >= '0' && s[i] <= '6') {
                    ways_two_digits = 2;
                } else {
                    ways_two_digits = 1;
                }
            } else if (prev_char == '1') {
                if (s[i] == '*') {
                    ways_two_digits = 9;
                } else {
                    ways_two_digits = 1;
                }
            } else if (prev_char == '2') {
                if (s[i] == '*') {
                    ways_two_digits = 6;
                } else if (s[i] >= '0' && s[i] <= '6') {
                    ways_two_digits = 1;
                } else {
                    ways_two_digits = 0;
                }
            } else {
                ways_two_digits = 0;
            }
            
            current_ways = (current_ways + (prev_two * ways_two_digits) % MOD) % MOD;
            
            prev_two = prev_one;
            prev_one = current_ways;
        }
        
        return (int)prev_one;
    }
};