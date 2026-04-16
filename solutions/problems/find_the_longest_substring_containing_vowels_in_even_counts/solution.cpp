class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> firstPos;
        int mask = 0;
        int maxLen = 0;
        firstPos[0] = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // อัปเดต mask
            switch (s[i]) {
                case 'a': mask ^= 1 << 0; break;
                case 'e': mask ^= 1 << 1; break;
                case 'i': mask ^= 1 << 2; break;
                case 'o': mask ^= 1 << 3; break;
                case 'u': mask ^= 1 << 4; break;
            }
            
            if (firstPos.count(mask)) {
                maxLen = max(maxLen, i + 1 - firstPos[mask]);
            } else {
                firstPos[mask] = i + 1;
            }
        }
        
        return maxLen;
    }
};