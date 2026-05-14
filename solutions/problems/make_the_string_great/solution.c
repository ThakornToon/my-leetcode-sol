char* makeGood(char* s) {
    int n = strlen(s);
    int writeIdx = 0;
    
    for (int i = 0; i < n; i++) {
        if (writeIdx > 0 && 
            abs(s[writeIdx - 1] - s[i]) == 32) {
            writeIdx--;  // ลบตัวก่อนหน้า
        } else {
            s[writeIdx++] = s[i];  // เก็บตัวปัจจุบัน
        }
    }
    
    s[writeIdx] = '\0';
    return s;
}