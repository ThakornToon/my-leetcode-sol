/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    // 1. รวมประโยค
    char combined[500];
    snprintf(combined, sizeof(combined), "%s %s", s1, s2);
    
    // 2. แยกคำ
    char* words[100];  // เก็บคำสูงสุด 100 คำ
    int wordCount = 0;
    
    char* token = strtok(combined, " ");
    while (token != NULL && wordCount < 100) {
        words[wordCount] = strdup(token);  // สำเนาคำ
        wordCount++;
        token = strtok(NULL, " ");
    }
    
    // 3. หาคำที่ไม่ซ้ำ
    char** result = malloc(wordCount * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordCount; i++) {
        int count = 0;
        
        // นับว่าคำนี้ปรากฏกี่ครั้ง
        for (int j = 0; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        
        // ถ้าปรากฏครั้งเดียว → เก็บในผลลัพธ์
        if (count == 1) {
            result[*returnSize] = strdup(words[i]);
            (*returnSize)++;
        }
    }
    
    // 4. Free memory ของ words
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    
    return result;
}