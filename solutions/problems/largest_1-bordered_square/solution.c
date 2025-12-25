

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    
    // สร้าง arrays สำหรับ prefix sum แนวนอนแล้วแนวตั้ง
    int** hor = (int**)malloc(m * sizeof(int*));
    int** ver = (int**)malloc(m * sizeof(int*));
    
    for (int i = 0; i < m; i++) {
        hor[i] = (int*)malloc(n * sizeof(int));
        ver[i] = (int*)malloc(n * sizeof(int));
    }
    
    // คำนวณ prefix sum
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                hor[i][j] = (j == 0) ? 1 : hor[i][j-1] + 1;
                ver[i][j] = (i == 0) ? 1 : ver[i-1][j] + 1;
            } else {
                hor[i][j] = 0;
                ver[i][j] = 0;
            }
        }
    }
    
    int maxSize = 0;
    
    // ตรวจสอบทุกจุด
    for (int i = m-1; i >= maxSize; i--) {
        for (int j = n-1; j >= maxSize; j--) {
            if (grid[i][j] == 0) continue;
            
            // ขนาดที่เป็นไปได้
            int possibleSize = hor[i][j] < ver[i][j] ? hor[i][j] : ver[i][j];
            
            // ตรวจสอบจากขนาดใหญ่ไปเล็ก
            for (int size = possibleSize; size > maxSize; size--) {
                int top = i - size + 1;
                int left = j - size + 1;
                
                // ตรวจสอบว่าเป็นสี่เหลี่ยมจัตุรัสจริงๆ หรือไม่
                if (top >= 0 && left >= 0 && 
                    hor[top][j] >= size && 
                    ver[i][left] >= size) {
                    maxSize = size;
                    break;
                }
            }
        }
    }
    
    // free memory
    for (int i = 0; i < m; i++) {
        free(hor[i]);
        free(ver[i]);
    }
    free(hor);
    free(ver);
    
    return maxSize * maxSize;
}