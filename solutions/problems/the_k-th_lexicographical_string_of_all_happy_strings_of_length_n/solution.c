void backtrack(char* current, int pos, int n, int* count, int k, char* result) {
    if (pos == n) {
        (*count)++;
        if (*count == k) {
            strcpy(result, current);
        }
        return;
    }
    
    for (char c = 'a'; c <= 'c'; c++) {
        // ตรวจสอบว่าไม่ซ้ำกับตัวก่อนหน้า
        if (pos > 0 && current[pos - 1] == c) {
            continue;
        }
        
        current[pos] = c;
        backtrack(current, pos + 1, n, count, k, result);
        
        if (result[0] != '\0') return;  // เจอแล้วหยุด
    }
}

char* getHappyString(int n, int k) {
    // คำนวณจำนวน happy strings ทั้งหมด
    int total = 3;
    for (int i = 1; i < n; i++) {
        total *= 2;
    }
    
    if (k > total) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    
    char* result = (char*)malloc((n + 1) * sizeof(char));
    memset(result, 0, (n + 1) * sizeof(char));
    
    char* current = (char*)malloc((n + 1) * sizeof(char));
    memset(current, 0, (n + 1) * sizeof(char));
    
    int count = 0;
    backtrack(current, 0, n, &count, k, result);
    
    free(current);
    return result;
}