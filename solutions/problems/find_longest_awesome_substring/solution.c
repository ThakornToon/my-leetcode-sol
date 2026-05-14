#define MAX_MASK (1 << 10)  // 2^10 = 1024 masks สำหรับ 0-9
#define ALPHABET 10

int longestAwesome(char* s) {
    int n = strlen(s);
    
    // เก็บตำแหน่งแรกที่พบแต่ละ mask แต่ละ bit แทนจำนวนตัวอักษรแต่ละตัวเลข
    // 1 - จำนวนคี่, 0 - จำนวนคู่
    int firstPos[MAX_MASK];
    for (int i = 0; i < MAX_MASK; i++) {
        firstPos[i] = -1;
    }
    
    int mask = 0;
    int maxLen = 0;
    firstPos[0] = 0;  // mask 0 ที่ index 0
    
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        mask ^= (1 << digit);  // flip bit ของตัวเลขนี้
        
        // กรณีที่ 1: mask ปัจจุบัน (ทำให้ทุกตัวมีจำนวนคู่ได่้่่เลยไหม)
        if (firstPos[mask] != -1) {
            int len = i + 1 - firstPos[mask];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            firstPos[mask] = i + 1;
        }
        
        // กรณีที่ 2: ลอง flip แต่ละ bit (ทำให้มีตัวเลขคี่ 1 ตัว)
        for (int j = 0; j < ALPHABET; j++) {
            int targetMask = mask ^ (1 << j);
            if (firstPos[targetMask] != -1) {
                int len = i + 1 - firstPos[targetMask];
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }
    
    return maxLen;
}