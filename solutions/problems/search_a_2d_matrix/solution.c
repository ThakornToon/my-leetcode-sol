bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int top = 0;
    int bot = matrixSize - 1;

    while (top <= bot) {
        int mid = (top + bot) / 2;

        if (matrix[mid][0] <= target && matrix[mid][matrixColSize[mid] - 1] >= target) {
            break;
        } 
        else if (matrix[mid][0] > target) {
            bot = mid - 1;
        } 
        else {
            top = mid + 1;
        }
    }

    int row = (top + bot) / 2;
    int left = 0;
    int right = matrixColSize[row] - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (matrix[row][mid] == target) {
            return true;
        } 
        else if (matrix[row][mid] > target) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return false; 
}