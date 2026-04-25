char* reformat(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    
    // นับจำนวน
    int letterCount = 0, digitCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            letterCount++;
        } else {
            digitCount++;
        }
    }
    
    if (abs(letterCount - digitCount) > 1) {
        result[0] = '\0';
        return result;
    }
    
    int lPos = 0, dPos = 0;
    // กำหนดตำแหน่งเริ่มต้น
    if (letterCount > digitCount) {
        lPos = 0;
        dPos = 1;
    } else {
        lPos = 1;
        dPos = 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result[lPos] = s[i];
            lPos += 2;
        } else {
            result[dPos] = s[i];
            dPos += 2;
        }
    }
    result[n] = '\0';
    
    return result;
}