int max(int a, int b) {
    return (a >= b) ? a : b;
}

int go(int** matrix, int matrixSize, int* matrixColSize, int** mem, int startR, int startC) {
    if (mem[startR][startC] != 0) {
        return mem[startR][startC];
    }
    int count = 1;
    if (startR - 1 >= 0 && matrix[startR][startC] < matrix[startR - 1][startC]) {
        count = max(count, 1 + go(matrix, matrixSize, matrixColSize, mem, startR - 1, startC));
    }
    if (startR + 1 < matrixSize && matrix[startR][startC] < matrix[startR + 1][startC]) {
        count = max(count, 1 + go(matrix, matrixSize, matrixColSize, mem, startR + 1, startC));
    }
    if (startC - 1 >= 0 && matrix[startR][startC] < matrix[startR][startC - 1]) {
        count = max(count, 1 + go(matrix, matrixSize, matrixColSize, mem, startR, startC - 1));
    }
    if (startC + 1 < *matrixColSize && matrix[startR][startC] < matrix[startR][startC + 1]) {
        count = max(count, 1 + go(matrix, matrixSize, matrixColSize, mem, startR, startC + 1));
    }
    mem[startR][startC] = count;

    return count;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int** mem = (int**)calloc(matrixSize, sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        mem[i] = (int*)calloc(*matrixColSize, sizeof(int));
    }
    int count = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            count = max(count, go(matrix, matrixSize, matrixColSize, mem, i, j));
        }
    }
    return count;
}