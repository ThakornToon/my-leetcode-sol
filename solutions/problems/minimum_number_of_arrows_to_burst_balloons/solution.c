int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return (intervalA[1] > intervalB[1]) ? 1 : -1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    // เรียงลำดับ intervals ตามจุดสิ้นสุด
    qsort(points, pointsSize, sizeof(int*), compare); // qsort ส่ง pointers ไปยัง elements ของอาร์เรย์ที่ต้องการเรียงลำดับ
    
    int arrows = 1;
    int end = points[0][1];
    
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    
    return arrows;
}