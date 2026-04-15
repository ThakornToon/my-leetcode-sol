int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        int left = 0, right = n - 1;
        int firstNeg = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (grid[i][mid] < 0) {
                firstNeg = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        count += (n - firstNeg);
    }
    
    return count;
}