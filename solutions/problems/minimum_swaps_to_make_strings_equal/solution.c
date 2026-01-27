int minimumSwap(char* s1, char* s2) {
    int len = strlen(s1);
    int xy = 0;  // นับคู่ (x,y) ที่ s1[i]='x', s2[i]='y'
    int yx = 0;  // นับคู่ (y,x) ที่ s1[i]='y', s2[i]='x'
    
    // นับจำนวนตำแหน่งที่แตกต่างกัน
    for (int i = 0; i < len; i++) {
        if (s1[i] == 'x' && s2[i] == 'y') {
            xy++;
        } else if (s1[i] == 'y' && s2[i] == 'x') {
            yx++;
        }
    }
    
    // ตรวจสอบความเป็นไปได้
    // ผลรวมต้องเป็นเลขคู่ (เพราะแต่ละการสลับเปลี่ยน 2 ตำแหน่ง)
    if ((xy + yx) % 2 != 0) {
        return -1;
    }
    
    // คำนวนจำนวนการสลับน้อยที่สุด
    // xy/2 + yx/2 + (xy%2) * 2
    int swaps = (xy / 2) + (yx / 2) + (xy % 2) * 2;
    
    return swaps;
}