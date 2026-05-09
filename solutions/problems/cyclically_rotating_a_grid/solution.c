/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void rotateLayer(int** grid, int m, int n, int layer, int k) {
    int top = layer;
    int bottom = m - 1 - layer;
    int left = layer;
    int right = n - 1 - layer;
    
    int perimeter = 2 * (bottom - top + right - left);
    if (perimeter == 0) return;
    
    int* elements = (int*)malloc(perimeter * sizeof(int));
    int idx = 0;
    
    // top row (left to right)
    for (int j = left; j <= right; j++) {
        elements[idx++] = grid[top][j];
    }
    // right column (top+1 to bottom)
    for (int i = top + 1; i <= bottom; i++) {
        elements[idx++] = grid[i][right];
    }
    // bottom row (right-1 to left)
    for (int j = right - 1; j >= left; j--) {
        elements[idx++] = grid[bottom][j];
    }
    // left column (bottom-1 to top+1)
    for (int i = bottom - 1; i > top; i--) {
        elements[idx++] = grid[i][left];
    }
    
    // rotate
    int shift = k % perimeter;
    int* rotated = (int*)malloc(perimeter * sizeof(int));
    for (int i = 0; i < perimeter; i++) {
        rotated[i] = elements[(i + shift) % perimeter];
    }
    
    // put back
    idx = 0;
    for (int j = left; j <= right; j++) {
        grid[top][j] = rotated[idx++];
    }
    for (int i = top + 1; i <= bottom; i++) {
        grid[i][right] = rotated[idx++];
    }
    for (int j = right - 1; j >= left; j--) {
        grid[bottom][j] = rotated[idx++];
    }
    for (int i = bottom - 1; i > top; i--) {
        grid[i][left] = rotated[idx++];
    }
    
    free(elements);
    free(rotated);
}


int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize;
    int n = gridColSize[0];
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    int layers = (m < n ? m : n) / 2;
    
    for (int layer = 0; layer < layers; layer++) {
        rotateLayer(grid, m, n, layer, k);
    }
    
    return grid;
}