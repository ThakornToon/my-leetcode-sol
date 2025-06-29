/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int start;
    int index;
} IntervalStart; // เก็บจุดเริ่มต้นของแต่ละ index ในอาเรย์เดิม

int compare(const void *a, const void *b) {
    IntervalStart *ia = (IntervalStart *)a;
    IntervalStart *ib = (IntervalStart *)b;
    return ia->start - ib->start; // เรียงตามจุดเริ่มต้นน้อยไปมาก
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = intervalsSize;
    int* res = (int*)malloc(intervalsSize * sizeof(int));
    IntervalStart* starts = (IntervalStart*)malloc(intervalsSize * sizeof(IntervalStart)); // เก็บคู่ค่าจุดเริ่มต้นของแต่ละ index
    
    // เก็บจุดเริ่มต้นและ index ดั้งเดิม
    for (int i = 0; i < intervalsSize; i++) {
        starts[i].start = intervals[i][0];
        starts[i].index = i;
    }
    
    // เรียงลำดับตามจุดเริ่มต้น
    qsort(starts, intervalsSize, sizeof(IntervalStart), compare);
    
    // ค้นหาแต่ละช่วง
    for (int i = 0; i < intervalsSize; i++) {
        int end = intervals[i][1];
        int left = 0, right = intervalsSize;
        int found = -1;
        
        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (starts[mid].start < end) {
                left = mid + 1;
            } else {
                right = mid;
                found = starts[mid].index;
            }
        }
        
        res[i] = found;
    }
    
    free(starts);
    return res;    
}