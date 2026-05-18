class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstPos(26, -1);  // เก็บตำแหน่งแรกของแต่ละตัวอักษร
        int maxLen = -1;
        
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            
            if (firstPos[idx] == -1) {
                firstPos[idx] = i;  // เก็บตำแหน่งแรก
            } else {
                // คำนวณระยะห่างและ update ค่าสูงสุด
                maxLen = max(maxLen, i - firstPos[idx] - 1);
            }
        }
        
        return maxLen;
    }
};