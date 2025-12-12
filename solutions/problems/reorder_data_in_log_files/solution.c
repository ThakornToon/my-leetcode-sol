/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_LOGS 100
#define MAX_LEN 100

// ตรวจสอบว่าเป็น digit-log หรือ letter-log
bool isDigitLog(char* log) {
    // ข้าม identifier (คำแรก)
    char* space = strchr(log, ' ');
    
    // ตรวจสอบตัวอักษรถัดจาก space แรกว่าเป็นตัวเลขหรือไม่
    return isdigit(space[1]);
}

// เปรียบเทียบ letter logs สำหรับการ sort
int compareLetterLogs(const void* a, const void* b) {
    char* log1 = *(char**)a;
    char* log2 = *(char**)b;
    
    // หาตำแหน่งของ space แรก (separator ระหว่าง identifier กับ content)
    char* space1 = strchr(log1, ' ');
    char* space2 = strchr(log2, ' ');
    
    // เปรียบเทียบ content (ส่วนหลัง space)
    int content_cmp = strcmp(space1 + 1, space2 + 1);
    
    // ถ้า content เท่ากัน ให้เปรียบเทียบ identifier
    if (content_cmp == 0) {
        // copy identifier เพื่อเปรียบเทียบ 
        // การลบ pointer = จำนวน characters ระหว่างสอง pointer
        int len1 = space1 - log1;
        int len2 = space2 - log2;
        
        char id1[MAX_LEN], id2[MAX_LEN];
        strncpy(id1, log1, len1);
        strncpy(id2, log2, len2);
        id1[len1] = '\0';
        id2[len2] = '\0';
        
        return strcmp(id1, id2);
    }
    
    return content_cmp;
}

char** reorderLogFiles(char** logs, int logsSize, int* returnSize) {
    // แยก letter logs และ digit logs
    char** letterLogs = (char**)malloc(logsSize * sizeof(char*));
    char** digitLogs = (char**)malloc(logsSize * sizeof(char*));
    int letterCount = 0;
    int digitCount = 0;
    
    for (int i = 0; i < logsSize; i++) {
        if (isDigitLog(logs[i])) {
            digitLogs[digitCount++] = logs[i];
        } else {
            letterLogs[letterCount++] = logs[i];
        }
    }
    
    // Sort letter logs
    qsort(letterLogs, letterCount, sizeof(char*), compareLetterLogs);
    
    // ใส่ digit logs ตาม (เรียงตามลำดับเดิม)
    for (int i = 0; i < digitCount; i++) {
        letterLogs[letterCount++] = digitLogs[i];
    }
    
    *returnSize = logsSize;
    
    free(digitLogs);
    
    return letterLogs;
}