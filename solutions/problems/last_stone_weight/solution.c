int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int lastStoneWeight(int* stones, int stonesSize) {
    int n = stonesSize;
    
    while (n > 1) {
        // เรียงจากมากไปน้อย
        qsort(stones, n, sizeof(int), compare);
        
        // นำสองก้อนแรก (ใหญ่ที่สุด) มาเปรียบเทียบ
        int y = stones[0];  // ก้อนใหญ่ที่สุด
        int x = stones[1];  // ก้อนใหญ่รองลงมา
        
        if (x == y) {
            // ทำลายทั้งสองก้อน
            for (int i = 0; i < n - 2; i++) {
                stones[i] = stones[i + 2];
            }
            n -= 2;
        } else {
            // ทำลายก้อนเล็กกว่า, ก้อนใหญ่เหลือผลต่าง
            stones[0] = y - x;
            for (int i = 1; i < n - 1; i++) {
                stones[i] = stones[i + 1];
            }
            n -= 1;
        }
    }
    
    return n == 0 ? 0 : stones[0];
}