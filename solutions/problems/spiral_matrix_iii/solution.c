/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    
    // ทิศทาง: ขวา, ล่าง, ซ้าย, บน
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int r = rStart, c = cStart;
    int step = 1;
    int dir = 0;
    int count = 0;
    
    // เพิ่มจุดเริ่มต้น
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = r;
    result[count][1] = c;
    (*returnColumnSizes)[count] = 2;
    count++;
    
    while (count < total) {
        // เดิน 2 ทิศทางด้วย step เดียวกัน
        for (int i = 0; i < 2; i++) {
            // เดิน step ก้าวในทิศทางปัจจุบัน
            for (int j = 0; j < step; j++) {
                r += dirs[dir][0];
                c += dirs[dir][1];
                
                // ตรวจสอบขอบเขต
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result[count] = (int*)malloc(2 * sizeof(int));
                    result[count][0] = r;
                    result[count][1] = c;
                    (*returnColumnSizes)[count] = 2;
                    count++;
                    
                    if (count == total) {
                        *returnSize = count;
                        return result;
                    }
                }
            }
            // เปลี่ยนทิศทาง
            dir = (dir + 1) % 4;
        }
        // เพิ่ม step
        step++;
    }
    
    *returnSize = count;
    return result;
}