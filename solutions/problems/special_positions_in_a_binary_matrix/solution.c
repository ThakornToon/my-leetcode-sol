int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    
    // นับจำนวน 1 ในแต่ละแถวและคอลัมน์
    int* rowCount = (int*)calloc(m, sizeof(int));
    int* colCount = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }
    
    // ตรวจสอบตำแหน่งที่เป็น special
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                result++;
            }
        }
    }
    
    free(rowCount);
    free(colCount);
    
    return result;
}