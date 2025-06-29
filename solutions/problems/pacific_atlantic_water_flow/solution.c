/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** heights, int rows, int cols, bool** visited, int i, int j, int prevHeight) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || heights[i][j] < prevHeight) { // ดูว่าไหลมาได้ไหม
        return;
    }
    
    visited[i][j] = true;
    
    // ตรวจสอบ 4 ทิศทาง
    dfs(heights, rows, cols, visited, i+1, j, heights[i][j]);
    dfs(heights, rows, cols, visited, i-1, j, heights[i][j]);
    dfs(heights, rows, cols, visited, i, j+1, heights[i][j]);
    dfs(heights, rows, cols, visited, i, j-1, heights[i][j]);
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int rows = heightsSize;
    int cols = heightsColSize[0];
    
    // สร้าง visited arrays
    bool** pacific = (bool**)malloc(rows * sizeof(bool*));
    bool** atlantic = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        pacific[i] = (bool*)calloc(cols, sizeof(bool));
        atlantic[i] = (bool*)calloc(cols, sizeof(bool));
    }
    
    // ตรวจสอบจากขอบแปซิฟิก
    for (int i = 0; i < rows; i++) {
        dfs(heights, rows, cols, pacific, i, 0, INT_MIN);
    }
    for (int j = 0; j < cols; j++) {
        dfs(heights, rows, cols, pacific, 0, j, INT_MIN);
    }
    
    // ตรวจสอบจากขอบแอตแลนติก
    for (int i = 0; i < rows; i++) {
        dfs(heights, rows, cols, atlantic, i, cols-1, INT_MIN);
    }
    for (int j = 0; j < cols; j++) {
        dfs(heights, rows, cols, atlantic, rows-1, j, INT_MIN);
    }
    
    // นับผลลัพธ์
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                count++;
            }
        }
    }
    
    // จอง memory สำหรับผลลัพธ์
    int** result = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    *returnSize = count;
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result[index] = (int*)malloc(2 * sizeof(int));
                result[index][0] = i;
                result[index][1] = j;
                (*returnColumnSizes)[index] = 2;
                index++;
            }
        }
    }
    
    // คืน memory
    for (int i = 0; i < rows; i++) {
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);
    
    return result;
}