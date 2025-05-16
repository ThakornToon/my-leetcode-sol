void swap(int** matrix, int i1, int j1, int i2, int j2) {
    int temp = matrix[i1][j1];
    matrix[i1][j1] = matrix[i2][j2];
    matrix[i2][j2] = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i=0; i<matrixSize; i++){
        for(int j=i; j<matrixSize; j++){
            if(j>=i){
                swap(matrix, i, j, j, i);
            }
        }
    }
    int mirror;
    if(matrixSize%2==0){
        mirror = matrixSize/2;
    }
    else{
        mirror = matrixSize/2+1;
    }
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<mirror; j++){
            swap(matrix, i, j, i, matrixSize-j-1);
        }
    }
}