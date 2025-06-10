/*
Pattern
1 1
1 #(2)
*/
int min(int a, int b) {
    return (a <= b) ? a : b;
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int row = matrixSize, col = *matrixColSize;
    int dp[row + 1][col + 1];
    int side = 0;
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = 0;
                if (matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    side = (dp[i][j] > side) ? dp[i][j] : side;
                }

            }
        }
    }
    return side * side;
}