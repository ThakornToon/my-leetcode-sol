int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    const int MOD = 1000000007;
    
    // เพิ่ม fences ขอบ
    int* hPoints = (int*)malloc((hFencesSize + 2) * sizeof(int));
    int* vPoints = (int*)malloc((vFencesSize + 2) * sizeof(int));
    
    for (int i = 0; i < hFencesSize; i++) hPoints[i] = hFences[i];
    hPoints[hFencesSize] = 1;
    hPoints[hFencesSize + 1] = m;
    int hTotal = hFencesSize + 2;
    
    for (int i = 0; i < vFencesSize; i++) vPoints[i] = vFences[i];
    vPoints[vFencesSize] = 1;
    vPoints[vFencesSize + 1] = n;
    int vTotal = vFencesSize + 2;
    
    qsort(hPoints, hTotal, sizeof(int), compare);
    qsort(vPoints, vTotal, sizeof(int), compare);
    
    // ใช้ boolean array ถ้า m, n ไม่ใหญ่เกินไป
    int maxDist = m > n ? m : n;
    int* gapExists = (int*)calloc(maxDist + 1, sizeof(int));
    
    // คำนวณ gaps แนวนอน
    for (int i = 0; i < hTotal; i++) {
        for (int j = i + 1; j < hTotal; j++) {
            int diff = hPoints[j] - hPoints[i];
            if (diff <= maxDist) {
                gapExists[diff] = 1;
            }
        }
    }
    
    // หา gap ที่ใหญ่ที่สุดที่เป็น common
    long long maxSide = 0;
    for (int i = 0; i < vTotal; i++) {
        for (int j = i + 1; j < vTotal; j++) {
            int diff = vPoints[j] - vPoints[i];
            if (diff <= maxDist && gapExists[diff]) {
                if (diff > maxSide) {
                    maxSide = diff;
                }
            }
        }
    }
    
    free(hPoints);
    free(vPoints);
    free(gapExists);
    
    return (maxSide == 0) ? -1 : (maxSide * maxSide) % MOD;

}