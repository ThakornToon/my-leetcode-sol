char* reorderSpaces(char* text) {
    int n = strlen(text);
    
    // นับจำนวนช่องว่างและคำ
    int spaceCount = 0;
    int wordCount = 0;
    int inWord = 0;
    
    for (int i = 0; i < n; i++) {
        if (text[i] == ' ') {
            spaceCount++;
            inWord = 0;
        } else {
            if (inWord == 0) {
                wordCount++;
                inWord = 1;
            }
        }
    }
    
    // ถ้าไม่มีคำ หรือมีคำเดียว
    if (wordCount <= 1) {
        // เอาช่องว่างทั้งหมดไว้ต่อท้าย
        char* result = (char*)malloc((n + 1) * sizeof(char));
        int idx = 0;
        
        // คัดลอกคำ (เอาช่องว่างออก)
        for (int i = 0; i < n; i++) {
            if (text[i] != ' ') {
                result[idx++] = text[i];
            }
        }
        
        // เพิ่มช่องว่างต่อท้าย
        for (int i = 0; i < spaceCount; i++) {
            result[idx++] = ' ';
        }
        result[idx] = '\0';
        return result;
    }
    
    // คำนวณช่องว่างระหว่างคำและเศษ
    int spacesBetween = spaceCount / (wordCount - 1);
    int extraSpaces = spaceCount % (wordCount - 1);
    
    // แยกคำทั้งหมด
    char** words = (char**)malloc(wordCount * sizeof(char*));
    int wordIdx = 0;
    int start = 0;
    
    for (int i = 0; i <= n; i++) {
        if (i == n || text[i] == ' ') {
            if (start < i) {
                // พบคำ
                int len = i - start;
                words[wordIdx] = (char*)malloc((len + 1) * sizeof(char));
                strncpy(words[wordIdx], text + start, len);
                words[wordIdx][len] = '\0';
                wordIdx++;
            }
            start = i + 1;
        }
    }
    
    // คำนวณขนาดผลลัพธ์
    int resultLen = n; // ความยาวเท่าเดิม
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    int idx = 0;
    
    // ต่อคำและช่องว่างระหว่างคำ
    for (int i = 0; i < wordCount; i++) {
        // ต่อคำ
        int wordLen = strlen(words[i]);
        strncpy(result + idx, words[i], wordLen);
        idx += wordLen;
        
        // ต่อช่องว่างระหว่างคำ (ยกเว้นคำสุดท้าย)
        if (i < wordCount - 1) {
            for (int j = 0; j < spacesBetween; j++) {
                result[idx++] = ' ';
            }
        }
    }
    
    // ต่อช่องว่างเศษท้าย
    for (int i = 0; i < extraSpaces; i++) {
        result[idx++] = ' ';
    }
    result[idx] = '\0';
    
    // คืนหน่วยความจำ
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
    
    return result;
}