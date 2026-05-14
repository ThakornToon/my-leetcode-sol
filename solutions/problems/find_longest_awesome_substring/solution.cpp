class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        // mask : fristIndex
        unordered_map<int, int> firstPos;
        
        // แต่ละ bit แทนแต่ละตัวเลข 0-9
        // 1 - จำนวนคี่, 0 - จำนวนคู่
        int mask = 0;
        int maxLen = 0;
        firstPos[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            mask ^= (1 << digit);
            
            // กรณี mask ปัจจุบันทำให้ทุดเลขมีจำนวนคู่ได้
            if (firstPos.count(mask)) {
                maxLen = max(maxLen, i + 1 - firstPos[mask]);
            } else {
                firstPos[mask] = i + 1;
            }
            
            // กรณี flip 1 bit มีจำนวนคี่ 1 ตัว
            for (int j = 0; j < 10; j++) {
                int targetMask = mask ^ (1 << j);
                if (firstPos.count(targetMask)) {
                    maxLen = max(maxLen, i + 1 - firstPos[targetMask]);
                }
            }
        }
        
        return maxLen;
    }
};