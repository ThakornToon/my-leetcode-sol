/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* matrix_spiral = malloc(sizeof(int) * (matrixSize * (*matrixColSize)));
    int top = 0, bottom = matrixSize - 1;
    int rigth = *matrixColSize - 1, left = 0;
    int offset = 0;
    *returnSize = matrixSize * (*matrixColSize);
    while (top <= bottom && left <= rigth) {
        for (int i = left; i <= rigth; i++) {
            matrix_spiral[offset++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
        matrix_spiral[offset++] = matrix[i][rigth];
        }
        rigth--;

        if (top <= bottom) {
        for (int i = rigth; i >= left; i--) {
            matrix_spiral[offset++] = matrix[bottom][i];
        }
        bottom--;
        }

        if (left <= rigth) {
        for (int i = bottom; i >= top; i--) {
            matrix_spiral[offset++] = matrix[i][left];
        }
        left++;
        }
    }
    return matrix_spiral;
}