/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countDiff(char* a, char* b, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }
    return diff;
}

char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    int wordLen = strlen(queries[0]);
    
    // จองพื้นที่สำหรับผลลัพธ์ (มากสุด queriesSize)
    char** result = (char**)malloc(queriesSize * sizeof(char*));
    *returnSize = 0;
    
    // ตรวจสอบแต่ละคำใน queries
    for (int i = 0; i < queriesSize; i++) {
        bool found = false;
        
        // ตรวจสอบกับทุกคำใน dictionary
        for (int j = 0; j < dictionarySize; j++) {
            int diff = countDiff(queries[i], dictionary[j], wordLen);
            if (diff <= 2) {
                found = true;
                break;
            }
        }
        
        if (found) {
            // เก็บคำในผลลัพธ์ (ต้อง malloc ใหม่)
            result[*returnSize] = (char*)malloc((wordLen + 1) * sizeof(char));
            strcpy(result[*returnSize], queries[i]);
            (*returnSize)++;
        }
    }
    
    return result;
}