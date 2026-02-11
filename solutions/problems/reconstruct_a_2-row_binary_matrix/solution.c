/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes) {
    // ตรวจสอบความเป็นไปได้เบื้องต้น
    int totalSum = 0;
    int twos = 0;
    int ones = 0;
    
    for (int i = 0; i < colsumSize; i++) {
        totalSum += colsum[i];
        if (colsum[i] == 2) {
            twos++;
        } else if (colsum[i] == 1) {
            ones++;
        }
    }
    
    // ตรวจสอบเงื่อนไข
    if (totalSum != upper + lower) {
        *returnSize = 0;
        return NULL;
    }
    
    if (upper < twos || lower < twos) {
        *returnSize = 0;
        return NULL;
    }
    
    // จำนวน 1 ที่เหลือสำหรับ colsum=1
    int upperRemaining = upper - twos;
    int lowerRemaining = lower - twos;
    
    if (upperRemaining < 0 || lowerRemaining < 0 || 
        upperRemaining + lowerRemaining != ones) {
        *returnSize = 0;
        return NULL;
    }
    
    // สร้าง matrix
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(colsumSize * sizeof(int));
    }
    
    // กรอกข้อมูล
    for (int i = 0; i < colsumSize; i++) {
        if (colsum[i] == 2) {
            matrix[0][i] = 1;
            matrix[1][i] = 1;
        } else if (colsum[i] == 0) {
            matrix[0][i] = 0;
            matrix[1][i] = 0;
        } else { // colsum[i] == 1
            if (upperRemaining > 0) {
                matrix[0][i] = 1;
                matrix[1][i] = 0;
                upperRemaining--;
            } else {
                matrix[0][i] = 0;
                matrix[1][i] = 1;
                lowerRemaining--;
            }
        }
    }
    
    // เตรียมค่าที่ต้อง return
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = colsumSize;
    (*returnColumnSizes)[1] = colsumSize;
    
    return matrix;
}