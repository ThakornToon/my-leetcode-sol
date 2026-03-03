int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];  // เรียงตาม l จากน้อยไปมาก
    }
    return intervalB[1] - intervalA[1];      // ถ้า l เท่ากัน เรียง r จากมากไปน้อย
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    // เรียง intervals
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int count = 1;  // นับ interval แรก
    int* current = intervals[0];
    
    for (int i = 1; i < intervalsSize; i++) {
        int* interval = intervals[i];
        
        // ตรวจสอบว่า interval ปัจจุบันถูก cover โดย current หรือไม่
        if (interval[1] > current[1]) {
            // ไม่ถูก cover
            count++;
            current = interval;
        }
        // ถ้า interval[1] <= current[1] → ถูก cover (ไม่ต้องทำอะไร)
    }
    
    return count;
}