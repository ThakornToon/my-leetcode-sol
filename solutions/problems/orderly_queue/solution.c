int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* orderlyQueue(char* s, int k) {
    int n = strlen(s);
    char* result = (char*)malloc(n + 1);
    
    if (k == 1) {
        // หา rotation ที่น้อยที่สุด
        strcpy(result, s);
        
        // สร้าง doubled string
        char* doubled = (char*)malloc(2 * n + 1);
        strcpy(doubled, s);
        strcat(doubled, s);
        
        for (int i = 1; i < n; i++) {
            // เปรียบเทียบ substring i..i+n-1
            int cmp = strncmp(doubled + i, result, n);
            if (cmp < 0) {
                strncpy(result, doubled + i, n);
                result[n] = '\0';
            }
        }
        
        free(doubled);
    } else {
        // k >= 2: เรียงลำดับ
        strcpy(result, s);
        qsort(result, n, sizeof(char), compare);
    }
    
    return result;
}