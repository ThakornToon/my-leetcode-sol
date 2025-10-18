bool isExpressive(char* s, char* word) {
    int i = 0, j = 0;
    int s_len = strlen(s);
    int w_len = strlen(word);
    
    while (i < s_len && j < w_len) {
        if (s[i] != word[j]) return false;
        
        // นับความยาวกลุ่มปัจจุบันใน s
        int s_count = 0;
        char s_char = s[i];
        while (i < s_len && s[i] == s_char) {
            s_count++;
            i++;
        }
        
        // นับความยาวกลุ่มปัจจุบันใน word
        int w_count = 0;
        char w_char = word[j];
        while (j < w_len && word[j] == w_char) {
            w_count++;
            j++;
        }
        
        // ตรวจสอบกฎการขยาย
        if (s_count < w_count) return false;
        if (s_count < 3 && s_count != w_count) return false;
    }
    
    // ต้องจบทั้งคู่พร้อมกัน
    return i == s_len && j == w_len;
}

int expressiveWords(char* s, char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (isExpressive(s, words[i])) {
            count++;
        }
    }
    return count;
}