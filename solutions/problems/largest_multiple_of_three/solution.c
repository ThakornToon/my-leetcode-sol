int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;  // เรียงจากมากไปน้อย
}

char* largestMultipleOfThree(int* digits, int digitsSize) {
    // เรียง digits จากมากไปน้อย
    qsort(digits, digitsSize, sizeof(int), compare);
    
    int sum = 0;
    int count[10] = {0};
    
    for (int i = 0; i < digitsSize; i++) {
        sum += digits[i];
        count[digits[i]]++;
    }
    
    int remainder = sum % 3;
    
    if (remainder != 0) {
        // ลบ digit ที่มี remainder เท่ากับ remainder (ตัวเล็กสุด)
        int removed = 0;
        for (int i = remainder; i <= 9; i += 3) {
            if (count[i] > 0) {
                count[i]--;
                removed = 1;
                break;
            }
        }
        
        // ถ้ายังไม่ถูกลบ ให้ลบ remainder 3-remainder สองตัว
        if (!removed) {
            int target = 3 - remainder;
            int removedCount = 0;
            for (int i = target; i <= 9; i += 3) {
                while (count[i] > 0 && removedCount < 2) {
                    count[i]--;
                    removedCount++;
                }
                if (removedCount == 2) break;
            }
        }
    }
    
    // สร้างผลลัพธ์
    char* result = (char*)malloc((digitsSize + 1) * sizeof(char));
    int idx = 0;
    
    for (int i = 9; i >= 0; i--) {
        while (count[i]-- > 0) {
            result[idx++] = '0' + i;
        }
    }
    
    result[idx] = '\0';
    
    // กรณีไม่มีตัวเลข หรือมีแต่ 0
    if (idx == 0 || (result[0] == '0')) {
        if (idx > 0 && result[0] == '0') {
            result[0] = '0';
            result[1] = '\0';
        } else {
            result[0] = '\0';
        }
    }
    
    return result;
}