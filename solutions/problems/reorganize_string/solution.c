char* reorganizeString(char* s) {
    int count[26] = {0};
    int n = strlen(s);
    
    // นับความถี่
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    
    // หาตัวอักษรที่มีความถี่สูงสุด
    int maxCount = 0, maxIndex = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxIndex = i;
        }
    }
    
    // ตรวจสอบความเป็นไปได้
    if (maxCount > (n + 1) / 2) {
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    
    char* result = malloc(n + 1);
    int index = 0;
    
    // ใส่ตัวอักษรที่มีความถี่สูงสุดก่อนในตำแหน่งคู่
    while (count[maxIndex] > 0) {
        result[index] = 'a' + maxIndex;
        index += 2;
        count[maxIndex]--;
    }
    
    // ใส่ตัวอักษรที่เหลือ
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (index >= n) index = 1;  // กลับมาใส่ตำแหน่งคี่
            result[index] = 'a' + i;
            index += 2;
            count[i]--;
        }
    }
    
    result[n] = '\0';
    return result;
}