int min(int a, int b) {
    return a < b ? a : b;
}
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    // ย้ายเครื่องหมายไปไหนก็ได้ ถ้าเจอเพื่อนที่อยู่ติดกันสามารถทำลายเครื่องหมายทั้งคู่ได้
    long long sum = 0;
    int c = 0; // นับเครื่องหมายลบ
    int mini = INT_MAX;
    int n = matrixSize;
    int m = matrixColSize[0];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            sum += abs(matrix[i][j]);
            if(matrix[i][j] < 0) {
                c++;
            }
            mini = min(mini, abs(matrix[i][j])); // หาขนาดที่น้อยที่สุด
        }
    }

    if(c % 2) sum -= 2*mini;

    return sum;
}