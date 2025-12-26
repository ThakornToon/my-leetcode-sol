int countCharacters(char** words, int wordsSize, char* chars) {
    // นับความถี่ตัวอักษรใน chars
    int charCount[26] = {0};
    for (int i = 0; chars[i] != '\0'; i++) {
        charCount[chars[i] - 'a']++;
    }
    
    int totalLength = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        // สำเนา charCount สำหรับคำนี้
        int tempCount[26];
        memcpy(tempCount, charCount, sizeof(charCount));
        
        char* word = words[i];
        int canForm = 1;  // true
        
        // ตรวจสอบแต่ละตัวอักษร
        for (int j = 0; word[j] != '\0'; j++) {
            int index = word[j] - 'a';
            if (tempCount[index] == 0) {
                canForm = 0;  // false
                break;
            }
            tempCount[index]--;
        }
        
        if (canForm) {
            // คำนวณความยาวคำ
            int len = 0;
            while (word[len] != '\0') len++;
            totalLength += len;
        }
    }
    
    return totalLength;
}