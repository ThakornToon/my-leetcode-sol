#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    long long MOD = 1000000007;
    
    // dpMax[i][j] = ค่ามากสุดถึง (i,j)
    // dpMin[i][j] = ค่าน้อยสุดถึง (i,j)
    long long** dpMax = (long long**)malloc(m * sizeof(long long*));
    long long** dpMin = (long long**)malloc(m * sizeof(long long*));
    
    for (int i = 0; i < m; i++) {
        dpMax[i] = (long long*)malloc(n * sizeof(long long));
        dpMin[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            dpMax[i][j] = LLONG_MIN;
            dpMin[i][j] = LLONG_MAX;
        }
    }
    
    // ค่าเริ่มต้นที่ (0,0)
    dpMax[0][0] = grid[0][0];
    dpMin[0][0] = grid[0][0];
    
    // เติมแถวแรก
    for (int j = 1; j < n; j++) {
        dpMax[0][j] = dpMax[0][j-1] * grid[0][j];
        dpMin[0][j] = dpMin[0][j-1] * grid[0][j];
    }
    
    // เติมคอลัมน์แรก
    for (int i = 1; i < m; i++) {
        dpMax[i][0] = dpMax[i-1][0] * grid[i][0];
        dpMin[i][0] = dpMin[i-1][0] * grid[i][0];
    }
    
    // DP สำหรับเซลล์ที่เหลือ
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int val = grid[i][j];
            long long fromTopMax = dpMax[i-1][j] * val;
            long long fromTopMin = dpMin[i-1][j] * val;
            long long fromLeftMax = dpMax[i][j-1] * val;
            long long fromLeftMin = dpMin[i][j-1] * val;
            
            // ค่ามากสุด: max(จากบน, จากซ้าย) พิจารณาทั้ง max และ min
            dpMax[i][j] = MAX(
                MAX(fromTopMax, fromTopMin),
                MAX(fromLeftMax, fromLeftMin)
            );
            
            // ค่าน้อยสุด: min(จากบน, จากซ้าย) พิจารณาทั้ง max และ min
            dpMin[i][j] = MIN(
                MIN(fromTopMax, fromTopMin),
                MIN(fromLeftMax, fromLeftMin)
            );
        }
    }
    
    long long result = dpMax[m-1][n-1];
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        free(dpMax[i]);
        free(dpMin[i]);
    }
    free(dpMax);
    free(dpMin);
    
    return (result < 0) ? -1 : (int)(result % MOD);

}