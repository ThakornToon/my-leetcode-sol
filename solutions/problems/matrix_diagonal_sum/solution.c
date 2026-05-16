int diagonalSum(int** mat, int matSize, int* matColSize) {
    int n = matSize;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        // เพิ่มค่าจาก primary diagonal: mat[i][i]
        sum += mat[i][i];
        
        // เพิ่มค่าจาก secondary diagonal: mat[i][n-1-i]
        sum += mat[i][n - 1 - i];
    }
    
    // ถ้า n เป็นเลขคี่ ให้ลบค่ากลางที่ถูกนับซ้ำ
    if (n % 2 == 1) {
        int mid = n / 2;
        sum -= mat[mid][mid];
    }
    
    return sum;
}