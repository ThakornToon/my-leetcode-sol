int minOperations(char* s) {
    int n = strlen(s);
    int count1 = 0;  // นับจำนวนที่ต่างจาก pattern1 (0101...)
    int count2 = 0;  // นับจำนวนที่ต่างจาก pattern2 (1010...)
    
    for (int i = 0; i < n; i++) {
        // pattern1: ตำแหน่งคู่ควรเป็น '0', ตำแหน่งคี่ควรเป็น '1'
        if (i % 2 == 0) {
            // ตำแหน่งคู่
            if (s[i] != '0') count1++;
            if (s[i] != '1') count2++;
        } else {
            // ตำแหน่งคี่
            if (s[i] != '1') count1++;
            if (s[i] != '0') count2++;
        }
    }
    
    return MIN(count1, count2);
}