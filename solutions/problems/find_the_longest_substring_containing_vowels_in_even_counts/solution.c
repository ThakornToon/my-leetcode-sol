#define MAX_MASK 32

int findTheLongestSubstring(char* s) {
    int n = strlen(s);
    
    // กำหนด bit สำหรับสระแต่ละตัว
    // a: bit 0, e: bit 1, i: bit 2, o: bit 3, u: bit 4
    int vowelMask[26] = {0};
    vowelMask['a' - 'a'] = 1 << 0;
    vowelMask['e' - 'a'] = 1 << 1;
    vowelMask['i' - 'a'] = 1 << 2;
    vowelMask['o' - 'a'] = 1 << 3;
    vowelMask['u' - 'a'] = 1 << 4;
    
    // เก็บตำแหน่งแรกที่พบ mask แต่ละค่า
    int firstPos[MAX_MASK];
    for (int i = 0; i < MAX_MASK; i++) {
        firstPos[i] = -1;
    }
    
    int mask = 0;
    int maxLen = 0;
    firstPos[0] = 0;  // mask 0 ที่ตำแหน่งเริ่มต้น
    
    for (int i = 0; i < n; i++) {
        // อัปเดต mask
        mask ^= vowelMask[s[i] - 'a'];
        
        // ถ้าเคยเจอ mask นี้มาก่อน
        if (firstPos[mask] != -1) {
            int len = i + 1 - firstPos[mask];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            firstPos[mask] = i + 1;
        }
    }
    
    return maxLen;
}