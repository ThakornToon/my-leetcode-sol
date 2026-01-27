class Solution {
    public int minimumSwap(String s1, String s2) {
        int xy = 0;  // นับ (x,y) pairs
        int yx = 0;  // นับ (y,x) pairs
        
        // นับตำแหน่งที่แตกต่างกัน
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            
            if (c1 != c2) {
                if (c1 == 'x') {
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
        // xy/2 + yx/2 + (xy%2)*2
        return (xy / 2) + (yx / 2) + (xy % 2) * 2;
    }
}