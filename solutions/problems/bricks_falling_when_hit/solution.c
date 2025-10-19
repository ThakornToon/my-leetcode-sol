/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// นับอิฐไม่ stable ที่จะกลายเป็น stable และ mark ไปด้วย(นับอิฐฟื้นฟู)
int markStable(int** grid, bool** stable, int m, int n, int i, int j) {
    // ดูว่าเงื่อนไขปัจจุบันจะทำให้เปลี่ยนเป็น stable ไหม (ถ้า stable อยู่แล้วเราจะไม่สนใจ)
    if (i < 0 || i >= m || j < 0 || j >= n) return 0;
    if (grid[i][j] != 1) return 0;
    if (stable[i][j]) return 0;
    
    // ถ้าปัจจุบัน stable จะขยายไปรอบๆด้วย
    stable[i][j] = true;
    int count = 1;
    
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (int d = 0; d < 4; d++) {
        count += markStable(grid, stable, m, n, i + dirs[d][0], j + dirs[d][1]);
    }
    
    return count;
}

int* hitBricks(int** grid, int gridSize, int* gridColSize, int** hits, int hitsSize, int* hitsColSize, int* returnSize) {
    int m = gridSize, n = gridColSize[0];
    *returnSize = hitsSize;
    int* result = (int*)calloc(hitsSize, sizeof(int));
    
    // Create working grid
    int** work = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        work[i] = (int*)malloc(n * sizeof(int));
        memcpy(work[i], grid[i], n * sizeof(int));
    }
    
    // Create stable array
    bool** stable = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        stable[i] = (bool*)calloc(n, sizeof(bool));
    }
    
    // จำลองการตีอิฐทั้งหมดก่อน
    for (int k = 0; k < hitsSize; k++) {
        int i = hits[k][0], j = hits[k][1];
        if (work[i][j] == 1) {
            work[i][j] = 0;
        }
    }
    
    // Mark stable bricks (ที่ยังเชื่อมต่อกับด้านบน)
    for (int j = 0; j < n; j++) {
        if (work[0][j] == 1) {
            markStable(work, stable, m, n, 0, j);
        }
    }
    
    // Process in reverse
    for (int k = hitsSize - 1; k >= 0; k--) {
        int i = hits[k][0], j = hits[k][1];
        
        if (grid[i][j] == 0) continue;
        
        // ถ้าตีโดนอิฐจริงๆ

        work[i][j] = 1; // เอาก้อนอิฐกลับมา
        // เช็คว่าก้อนนี้เชื่อมกับ stable หรือไม่
        bool connected = false;
        if (i == 0) { // อยู่แถวบนสุด
            connected = true;
        } else {
            // เช็คเพื่อนบ้านว่ามี stable ไหม
            int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0], nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && stable[ni][nj]) {
                    connected = true;
                    break;
                }
            }
        }
        // ถ้าก้อนนี้่ stable
        if (connected && !stable[i][j]) {
            // นับอิฐที่กลับมาเชื่อมต่อใหม่
            int count = markStable(work, stable, m, n, i, j) - 1; // ไม่นับก่อนที่ตี
            result[k] = count > 0 ? count : 0;
        }
    }
    
    // Cleanup
    for (int i = 0; i < m; i++) {
        free(work[i]);
        free(stable[i]);
    }
    free(work);
    free(stable);
    
    return result;
}