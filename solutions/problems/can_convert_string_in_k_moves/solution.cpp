class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        
        // shift : count 
        unordered_map<int, int> freq;
        
        for (int i = 0; i < s.length(); i++) {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff == 0) continue;
            
            freq[diff]++;
            
            int required = diff + (freq[diff] - 1) * 26;
            if (required > k) {
                return false;
            }
        }
        
        return true;
    }
};