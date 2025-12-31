char* removeDuplicates(char* s, int k) {
    int n = strlen(s);
    // จอง memory สำหรับ stack
    char* chars = (char*)malloc(n * sizeof(char));
    int* counts = (int*)malloc(n * sizeof(int));
    int top = -1;  // ดัชนีบนสุดของ stack
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        
        if (top >= 0 && chars[top] == c) {
            // ตัวอักษรเหมือนกับบนสุดของ stack
            counts[top]++;
            
            // ตรวจสอบถ้าถึง k
            if (counts[top] == k) {
                top--;  // pop
            }
        } else {
            // ตัวอักษรใหม่
            top++;
            chars[top] = c;
            counts[top] = 1;
        }
    }
    
    // คำนวณความยาวผลลัพธ์
    int resultLen = 0;
    for (int i = 0; i <= top; i++) {
        resultLen += counts[i];
    }
    
    // สร้างผลลัพธ์
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    int idx = 0;
    
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < counts[i]; j++) {
            result[idx++] = chars[i];
        }
    }
    result[idx] = '\0';
    
    // คืน memory
    free(chars);
    free(counts);
    
    return result;
}