// คืนค่า -1 ถ้ามีตัวอักษรซ้ำ
int stringToMask(char* s) {
    int mask = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        int bit = 1 << (s[i] - 'a');
        
        // ตรวจสอบว่ามีตัวอักษรนี้แล้วหรือไม่
        if (mask & bit) {
            return -1;  // มีตัวอักษรซ้ำ
        }
        
        mask |= bit;
    }
    
    return mask;
}

// DFS
void dfs(char** arr, int* masks, int arrSize, int index, int currentMask, int currentLength, int* maxLength) {
    // อัปเดตความยาวสูงสุด
    if (currentLength > *maxLength) {
        *maxLength = currentLength;
    }
    
    // ฐาน: ตรวจสอบครบทุกสตริงแล้ว
    if (index == arrSize) {
        return;
    }
    
    // พิจารณาสตริงที่ index
    // 1. ไม่เลือกสตริงนี้
    dfs(arr, masks, arrSize, index + 1, currentMask, currentLength, maxLength);
    
    // 2. เลือกสตริงนี้ (ถ้า mask ถูกต้องและไม่ชนกับ currentMask)
    if (masks[index] != -1 && (currentMask & masks[index]) == 0) {
        dfs(arr, masks, arrSize, index + 1, 
            currentMask | masks[index], 
            currentLength + strlen(arr[index]), 
            maxLength);
    }
}

int maxLength(char** arr, int arrSize) {
    // แปลงสตริงทั้งหมดเป็น masks
    int* masks = (int*)malloc(arrSize * sizeof(int));
    
    for (int i = 0; i < arrSize; i++) {
        masks[i] = stringToMask(arr[i]);
    }
    
    int maxLen = 0;
    dfs(arr, masks, arrSize, 0, 0, 0, &maxLen);
    
    free(masks);
    return maxLen;
}