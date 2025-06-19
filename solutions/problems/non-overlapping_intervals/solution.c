int compareIntervals(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[1] - interval2[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    // เรียงลำดับช่วงเวลาตามจุดสิ้นสุด น้อยไปมาก
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);
    
    int count = 0;
    int prevEnd = intervals[0][1];
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < prevEnd) {
            // มีการทับซ้อน ให้ลบช่วงเวลานี้
            count++;
        } else {
            // ไม่ทับซ้อน อัพเดท prevEnd
            prevEnd = intervals[i][1];
        }
    }
    
    return count;
}