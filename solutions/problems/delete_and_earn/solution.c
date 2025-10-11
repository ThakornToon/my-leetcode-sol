int max(int a, int b) {
    return (a >= b) ? a : b;
}

int deleteAndEarn(int* nums, int numsSize) {
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        maxNum = max(maxNum, nums[i]);
    }
    int* points = (int*)calloc(maxNum + 1, sizeof(int));
        
    // สร้าง points array แทนบ้านแต่ละหลัง / เมื่อลลบเลขนั้นๆ
    for (int i = 0; i < numsSize; i++) {
        points[nums[i]] += nums[i];
    }
        
    // เหมือน House Robber
    int prev2 = 0; // ลบหมายเลข 0
    int currentMax = points[1]; // ลบหมายเลข 1
    for (int i = 2; i <= maxNum; i++) {
        int current = max(currentMax, prev2 + points[i]); // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
        prev2 = currentMax; // ไม่ลบอันปัจจุบัน
        currentMax = current; // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
    }
        
    return currentMax;
}