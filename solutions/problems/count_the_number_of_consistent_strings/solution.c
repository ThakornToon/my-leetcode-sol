

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    // สร้าง boolean array สำหรับตัวอักษรที่อนุญาต (26 ตัว)
    bool allowedChars[26] = {false};
    
    // Mark ตัวอักษรที่อนุญาต
    for (int i = 0; allowed[i] != '\0'; i++) {
        allowedChars[allowed[i] - 'a'] = true;
    }
    
    int count = 0;
    
    // ตรวจสอบแต่ละ word
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        bool consistent = true;
        
        for (int j = 0; word[j] != '\0'; j++) {
            if (!allowedChars[word[j] - 'a']) {
                consistent = false;
                break;
            }
        }
        
        if (consistent) {
            count++;
        }
    }
    
    return count;
}