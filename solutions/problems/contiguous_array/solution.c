int findMaxLength(int* nums, int numsSize) {
    int* map = (int*)malloc((2 * numsSize + 1) * sizeof(int));
    for (int i = 0; i < 2 * numsSize + 1; i++) {
        map[i] = -2; // กำหนดค่าเริ่มต้น
    }
    
    int maxLen = 0;
    int sum = 0;
    map[numsSize] = -1; // prefix sum = 0 ที่ index -1
    
    for (int i = 0; i < numsSize; i++) {
        // แปลง 0 เป็น -1, 1 เป็น 1
        sum += (nums[i] == 0) ? -1 : 1;
        
        // ปรับ index ให้ไม่เป็นลบ
        int adjustedIndex = sum + numsSize;
        
        if (map[adjustedIndex] != -2) {
            // พบ prefix sum ซ้ำ → คำนวณความยาว
            int len = i - map[adjustedIndex];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // เก็บตำแหน่งแรกของ prefix sum นี้
            map[adjustedIndex] = i;
        }
    }
    
    free(map);
    return maxLen;
}