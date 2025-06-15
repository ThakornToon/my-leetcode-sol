bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int btw = 0;
    while (btw < matrixSize) {
        if (target >= matrix[btw][0] && target <= matrix[btw][(*matrixColSize) - 1]) {
            int left = 0;
            int right = (*matrixColSize) - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[btw][mid] == target) {
                    return true;
                } else if (matrix[btw][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            btw++;
        } else if (target > matrix[btw][0]) {
            btw++;
        } else if (target < matrix[btw][0]) {
            return false;
        }
    }
    return false;
}