char* sortString(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int resultIdx = 0;
    
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    
    int remaining = n;
    
    while (remaining > 0) {
        // เพิ่มจากน้อยไปมาก
        for (int i = 0; i < 26 && remaining > 0; i++) {
            if (count[i] > 0) {
                result[resultIdx++] = 'a' + i;
                count[i]--;
                remaining--;
            }
        }
        
        // เพิ่มจากมากไปน้อย
        for (int i = 25; i >= 0 && remaining > 0; i--) {
            if (count[i] > 0) {
                result[resultIdx++] = 'a' + i;
                count[i]--;
                remaining--;
            }
        }
    }
    
    result[resultIdx] = '\0';
    return result;
}