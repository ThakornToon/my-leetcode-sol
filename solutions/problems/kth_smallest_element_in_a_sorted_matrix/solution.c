int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int left = matrix[0][0], right = matrix[matrixSize - 1][matrixSize - 1];

    while (left < right) {
        int mid = left + (right - left) / 2; 
        int count = 0; // นับจำนวนค่าที่น้อยกว่า mid
        int col = matrixSize - 1;
        for (int row = 0; row < matrixSize; row++) {
            while (col >= 0 && matrix[row][col] > mid) {
                col--;
            }
            count += (col + 1);
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}