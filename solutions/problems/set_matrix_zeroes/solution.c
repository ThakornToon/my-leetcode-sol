void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool col0_0 = false;
    bool row0_0 = false;
    for (int i = 1; i < matrixSize; i++) {
        if(matrix[i][0] == 0) {
            col0_0 = true;
        }
    }
    for (int i = 1; i < matrixColSize[0]; i++) {
        if (matrix[0][i] == 0) {
            row0_0 = true;
        }
    }
    if (matrix[0][0] == 0) {
        col0_0 = true;
        row0_0 = true;
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    int max = matrixSize > matrixColSize[0] ? matrixSize : matrixColSize[0];
    for (int i = 1; i < max; i++) {
        if (i < matrixColSize[0] && matrix[0][i] == 0) {
            for (int j = 1; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
        if (i < matrixSize && matrix[i][0] == 0) { 
            for (int j = 1; j < matrixColSize[0]; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (row0_0) {
        for (int i = 0; i < matrixColSize[0]; i++) {
            matrix[0][i] = 0;
        }
    }
    if (col0_0) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}