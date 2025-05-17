/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)calloc(n, sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        res[i] = (int*)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int x = 0, y = 0, dx = 1, dy = 0;
    for (int i = 0; i < n * n; i++) {
        res[y][x] = i + 1;
        int new_x = x + dx;
        int new_y = y +dy;
        if (0 > new_x || new_x >= n || 0 > new_y || new_y >= n || res[new_y][new_x] != 0) { 
            int temp = dx;
            dx = -dy;
            dy = temp;
        }
        x += dx;
        y += dy;
    }
    return res;
}