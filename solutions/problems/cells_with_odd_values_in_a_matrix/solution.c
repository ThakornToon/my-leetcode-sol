int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    // สร้าง arrays สำหรับนับ
    int* row_count = (int*)calloc(m, sizeof(int));
    int* col_count = (int*)calloc(n, sizeof(int));
    
    // นับจำนวนครั้งที่แต่ละแถวและคอลัมน์ถูกเพิ่ม
    for (int k = 0; k < indicesSize; k++) {
        int ri = indices[k][0];
        int ci = indices[k][1];
        
        row_count[ri]++;
        col_count[ci]++;
    }
    
    // นับจำนวน cells คี่
    int oddCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((row_count[i] + col_count[j]) % 2 == 1) {
                oddCount++;
            }
        }
    }
    
    free(row_count);
    free(col_count);
    
    return oddCount;
}