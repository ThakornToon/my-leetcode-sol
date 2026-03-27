bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];
    
    // ลด k ให้อยู่ในช่วง [0, n-1] เพราะ shift n รอบกลับมาเหมือนเดิม
    k = k % n;
    if (k == 0) return true;  // shift 0 รอบ เหมือนเดิมเสมอ
    
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            // แถวคู่: shift ซ้าย k ตำแหน่ง
            // ตรวจสอบว่าแถวเดิมเท่ากับแถวที่ shift ซ้ายหรือไม่
            for (int j = 0; j < n; j++) {
                int original = mat[i][j];
                int shifted = mat[i][(j + k) % n];
                if (original != shifted) {
                    return false;
                }
            }
        } else {
            // แถวคี่: shift ขวา k ตำแหน่ง
            // shift ขวา k = shift ซ้าย n-k
            for (int j = 0; j < n; j++) {
                int original = mat[i][j];
                int shifted = mat[i][(j - k + n) % n];
                if (original != shifted) {
                    return false;
                }
            }
        }
    }
    
    return true;
}