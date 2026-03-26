

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize){
    // นับจำนวนคำ
    int wordCount = 0;
    int len = strlen(s);
    int maxLen = 0;
    int cnt = 0;

    // ค้นหาจำนวนคำ
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            wordCount++;
            cnt = 0;
        } else {
            cnt++;
            maxLen = (maxLen < cnt) ? cnt : maxLen;
        }
    }
    wordCount++; // คำสุดท้าย
    
    // แยกคำและเก็บความยาว
    char** words = (char**)malloc(wordCount * sizeof(char*));
    int* wordLengths = (int*)malloc(wordCount * sizeof(int));
    
    int wordIdx = 0;
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (i == len || s[i] == ' ') {
            int wordLen = i - start;
            words[wordIdx] = (char*)malloc((wordLen + 1) * sizeof(char));
            strncpy(words[wordIdx], s + start, wordLen);
            words[wordIdx][wordLen] = '\0';
            wordLengths[wordIdx] = wordLen;
            if (wordLen > maxLen) maxLen = wordLen;
            wordIdx++;
            start = i + 1;
        }
    }
    
    // สร้างผลลัพธ์แนวตั้ง
    *returnSize = maxLen;
    char** result = (char**)malloc(maxLen * sizeof(char*));
    
    for (int j = 0; j < maxLen; j++) {
        // สร้าง string สำหรับคอลัมน์ j
        char* col = (char*)malloc((wordCount + 1) * sizeof(char));
        int colLen = 0;
        
        for (int i = 0; i < wordCount; i++) {
            if (j < wordLengths[i]) {
                col[colLen++] = words[i][j];
            } else {
                col[colLen++] = ' ';
            }
        }
        
        // ตัดช่องว่างท้าย
        while (colLen > 0 && col[colLen - 1] == ' ') {
            colLen--;
        }
        
        col[colLen] = '\0';
        result[j] = (char*)malloc((colLen + 1) * sizeof(char));
        strcpy(result[j], col);
        free(col);
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
    free(wordLengths);
    
    return result;
}