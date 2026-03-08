char* findDifferentBinaryString(char** nums, int numsSize) {
    int n = numsSize;
    int total = 1 << n;  // 2^n
    
    // สร้าง array สำหรับ mark ว่ามี string ไหนบ้าง
    int* seen = (int*)calloc(total, sizeof(int));
    
    // แปลง binary string เป็น integer
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < n; j++) {
            val = val * 2 + (nums[i][j] - '0');
        }
        seen[val] = 1;
    }
    
    // หา integer ที่หายไป
    int missing = -1;
    for (int i = 0; i < total; i++) {
        if (!seen[i]) {
            missing = i;
            break;
        }
    }
    
    free(seen);
    
    // แปลง integer กลับเป็น binary string
    char* result = (char*)malloc((n + 1) * sizeof(char));
    for (int i = n - 1; i >= 0; i--) {
        result[i] = (missing % 2) + '0';
        missing /= 2;
    }
    result[n] = '\0';
    
    return result;
}