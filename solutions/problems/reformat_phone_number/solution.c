char* reformatNumber(char* number) {
    int n = strlen(number);
    
    // กรองเอาเฉพาะตัวเลข
    char* digits = (char*)malloc((n + 1) * sizeof(char));
    int digitCount = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(number[i])) {
            digits[digitCount++] = number[i];
        }
    }
    digits[digitCount] = '\0';
    
    // คำนวณขนาดผลลัพธ์
    int resultSize = digitCount + digitCount / 3 + 1;
    char* result = (char*)malloc(resultSize * sizeof(char));
    int idx = 0;
    int i = 0;
    
    while (i < digitCount) {
        int remaining = digitCount - i;
        
        if (remaining > 4) {
            // กลุ่มละ 3 ตัว
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
            result[idx++] = '-';
        } else if (remaining == 4) {
            // 2+2
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
            result[idx++] = '-';
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
        } else if (remaining == 3) {
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
        } else if (remaining == 2) {
            result[idx++] = digits[i++];
            result[idx++] = digits[i++];
        } else { // remaining == 1
            // ควรไม่เกิดเพราะ 1 จะถูกปรับในกรณี remaining>4
            result[idx++] = digits[i++];
        }
    }
    
    // ลบ dash ตัวสุดท้าย (ถ้ามี)
    if (idx > 0 && result[idx - 1] == '-') {
        idx--;
    }
    
    result[idx] = '\0';
    free(digits);
    return result;
}