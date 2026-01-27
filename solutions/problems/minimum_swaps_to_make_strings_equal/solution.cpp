class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        int n = s1.length();
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') {
                    xy++;  // pattern: (x,y)
                } else {
                    yx++;  // pattern: (y,x)
                }
            }
        }
        
        // ตรวจสอบความเป็นไปได้
        if ((xy + yx) % 2 != 0) {
            return -1;
        }
        
        // คำนวนจำนวนการสลับ
        // xy/2 + yx/2 + (xy%2) * 2
        return (xy / 2) + (yx / 2) + (xy % 2) * 2;
    }
};