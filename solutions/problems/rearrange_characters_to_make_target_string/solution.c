int rearrangeCharacters(char* s, char* target) {
    // นับความถี่ตัวอักษรใน s
    int countS[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        countS[s[i] - 'a']++;
    }
    
    // นับความถี่ตัวอักษรใน target
    int countTarget[26] = {0};
    for (int i = 0; target[i] != '\0'; i++) {
        countTarget[target[i] - 'a']++;
    }
    
    int maxCopies = INT_MAX;
    
    for (int i = 0; i < 26; i++) {
        if (countTarget[i] > 0) {
            // ถ้าใน target ต้องการตัวอักษรนี้ แต่ใน s ไม่มีเลย
            if (countS[i] == 0) {
                return 0;
            }
            
            // คำนวณจำนวนครั้งที่สร้างได้จากตัวอักษรนี้
            int copies = countS[i] / countTarget[i];
            if (copies < maxCopies) {
                maxCopies = copies;
            }
        }
    }
    
    return maxCopies;
}