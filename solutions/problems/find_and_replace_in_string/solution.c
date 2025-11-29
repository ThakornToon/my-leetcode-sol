int compare(const void* a, const void* b) {
    int* pair1 = *(int**)a;
    int* pair2 = *(int**)b;
    return pair1[0] - pair2[0];

}

char* findReplaceString(char* s, int* indices, int indicesSize, char** sources, int sourcesSize, char** targets, int targetsSize) {
    // สร้าง array สำหรับเรียงลำดับ
    int** sorted = malloc(indicesSize * sizeof(int*));
    for (int i = 0; i < indicesSize; i++) {
        sorted[i] = malloc(2 * sizeof(int));
        sorted[i][0] = indices[i];
        sorted[i][1] = i;
    }
    
    // เรียงลำดับ indices
    qsort(sorted, indicesSize, sizeof(int*), compare);
    
    // คำนวณความยาวผลลัพธ์สูงสุด
    int max_len = strlen(s) * 10; 
    char* result = malloc(max_len);
    int result_len = 0;
    int last_pos = 0;
    
    for (int i = 0; i < indicesSize; i++) {
        int pos = sorted[i][0];
        int idx = sorted[i][1];
        if (pos < last_pos) {
            continue;
        }
        char* source = sources[idx];
        char* target = targets[idx];
        int source_len = strlen(source);
        
        // เพิ่มส่วนก่อน replacement
        int copy_len = pos - last_pos;
        strncpy(result + result_len, s + last_pos, copy_len);
        result_len += copy_len;
        
        // ตรวจสอบว่า source ตรงหรือไม่
        if (strncmp(s + pos, source, source_len) == 0) {
            int target_len = strlen(target);
            strcpy(result + result_len, target);
            result_len += target_len;
            last_pos = pos + source_len;
        } else {
            last_pos = pos;
        }
        
        free(sorted[i]);
    }
    
    // เพิ่มส่วนที่เหลือ
    int remaining = strlen(s) - last_pos;
    strncpy(result + result_len, s + last_pos, remaining);
    result_len += remaining;
    result[result_len] = '\0';
    
    free(sorted);
    return result;
}