/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int isSubFolder(const char* parent, const char* child) {
    // child ต้องเริ่มต้นด้วย parent
    if (strncmp(parent, child, strlen(parent)) != 0) {
        return 0;
    }
    
    // หลังจาก parent ต้องมี '/' หรือ '\0' ใน child
    // เช่น "/a" และ "/ab" ไม่ใช่ parent-child
    int parent_len = strlen(parent);
    return (child[parent_len] == '/' || child[parent_len] == '\0');
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    // / > a
    // เรียงโฟลเดอร์ตามพาธ
    qsort(folder, folderSize, sizeof(char*), compareStrings);
    
    char** result = (char**)malloc(folderSize * sizeof(char*));
    *returnSize = 0;
    
    // โฟลเดอร์แรกย่อมไม่ใช่ sub-folder ของใคร
    result[(*returnSize)++] = folder[0];
    
    for (int i = 1; i < folderSize; i++) {
        // ตรวจสอบว่าโฟลเดอร์ปัจจุบันเป็น sub-folder ของโฟลเดอร์ล่าสุดในผลลัพธ์หรือไม่
        char* lastFolder = result[*returnSize - 1];
        
        if (!isSubFolder(lastFolder, folder[i])) {
            result[(*returnSize)++] = folder[i];
        }
    }
    
    return result;
}