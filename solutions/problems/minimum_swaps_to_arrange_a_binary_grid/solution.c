int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* trailingZeros = (int*)malloc(n * sizeof(int));
    
    // คำนวณ trailing zeros ของแต่ละแถว
    for (int i = 0; i < n; i++) {
        int zeros = 0;
        // นับจากขวาไปซ้าย
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 0) {
                zeros++;
            } else {
                break;
            }
        }
        trailingZeros[i] = zeros;
    }
    
    int swaps = 0;
    
    // จัดเรียงแถว
    for (int i = 0; i < n; i++) {
        int required = n - i - 1;  // จำนวน trailing zeros ที่ต้องการ
        int found = -1;
        
        // หาแถวที่เหมาะสมจากตำแหน่ง i ลงไป
        for (int j = i; j < n; j++) {
            if (trailingZeros[j] >= required) {
                found = j;
                break;
            }
        }
        
        // ถ้าไม่พบ แสดงว่าเป็นไปไม่ได้
        if (found == -1) {
            free(trailingZeros);
            return -1;
        }
        
        // สลับแถว found ขึ้นมาที่ 
        for (int j = found; j > i; j--) {
            // สลับ trailingZeros
            int temp = trailingZeros[j];
            trailingZeros[j] = trailingZeros[j - 1];
            trailingZeros[j - 1] = temp;
            swaps++;
        }
    }
    
    free(trailingZeros);
    return swaps;
}