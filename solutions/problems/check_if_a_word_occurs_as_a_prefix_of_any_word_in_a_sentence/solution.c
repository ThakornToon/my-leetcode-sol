int isPrefixOfWord(char* sentence, char* searchWord) {
    int wordIndex = 1;
    int i = 0;
    int n = strlen(sentence);
    int searchLen = strlen(searchWord);
    
    while (i < n) {
        // ตรวจสอบ prefix
        bool match = true;
        for (int j = 0; j < searchLen; j++) {
            if (i + j >= n || sentence[i + j] != searchWord[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return wordIndex;
        }
        
        // ข้ามไปคำถัดไป
        while (i < n && sentence[i] != ' ') {
            i++;
        }
        i++; // ข้าม space
        wordIndex++;
    }
    
    return -1;
}