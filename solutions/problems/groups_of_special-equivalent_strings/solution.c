int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

// ฟังก์ชันสร้าง signature
char* create_signature(const char* s, int len) {
    // กำหนดขนาดสูงสุด
    char* odd_chars = (char*)malloc(len + 1);
    char* even_chars = (char*)malloc(len + 1);
    int odd_idx = 0, even_idx = 0;
    
    // แยกตัวอักษร
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            even_chars[even_idx++] = s[i];
        } else {
            odd_chars[odd_idx++] = s[i];
        }
    }
    
    // ปิด string
    odd_chars[odd_idx] = '\0';
    even_chars[even_idx] = '\0';
    
    // เรียงลำดับ
    qsort(odd_chars, odd_idx, sizeof(char), compare);
    qsort(even_chars, even_idx, sizeof(char), compare);
    
    // รวม signature
    char* signature = (char*)malloc(len * 2 + 2);
    sprintf(signature, "%s#%s", odd_chars, even_chars);
    
    free(odd_chars);
    free(even_chars);
    
    return signature;
}

int numSpecialEquivGroups(char** words, int wordsSize) {
    // ใช้ array ธรรมดา (ถ้าขนาดไม่ใหญ่)
    char** signatures = (char**)malloc(wordsSize * sizeof(char*));
    int groups = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        char* sig = create_signature(words[i], strlen(words[i]));
        
        // ตรวจสอบว่า signature นี้มีอยู่แล้วหรือไม่
        int found = 0;
        for (int j = 0; j < groups; j++) {
            if (strcmp(signatures[j], sig) == 0) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            signatures[groups] = sig;
            groups++;
        } else {
            free(sig);
        }
    }
    
    // Free memory
    for (int i = 0; i < groups; i++) {
        free(signatures[i]);
    }
    free(signatures);
    
    return groups;
}