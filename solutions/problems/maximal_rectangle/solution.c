int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) {
        return 0;
    }
    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int));
    int maxArea = 0;
        
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '0') {
                heights[j] = 0;
            }
            else {
                heights[j] += 1;
            }
        }
            
        for (int j = 0; j < cols; j++) {
            int minHeight = INT_MAX;
            for (int k = j; k < cols; k++) {
                if (minHeight > heights[k]){
                    minHeight = heights[k];
                }
                int area = minHeight * (k - j + 1);
                if (maxArea < area) {
                    maxArea = area;
                }
            }
        }
    }
        
    return maxArea;
}