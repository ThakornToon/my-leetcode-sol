/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int r;
    int c;
    int dist;
} Cell;

int compare(const void* a, const void* b) {
    Cell* cellA = (Cell*)a;
    Cell* cellB = (Cell*)b;
    return cellA->dist - cellB->dist;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    Cell* cells = (Cell*)malloc(total * sizeof(Cell));
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = total;
    
    // Fill cells with coordinates and distances
    int index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cells[index].r = r;
            cells[index].c = c;
            cells[index].dist = abs(r - rCenter) + abs(c - cCenter);
            index++;
        }
    }
    
    // Sort cells by distance
    qsort(cells, total, sizeof(Cell), compare);
    
    // Prepare result
    for (int i = 0; i < total; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = cells[i].r;
        result[i][1] = cells[i].c;
        (*returnColumnSizes)[i] = 2;
    }
    
    free(cells);
    return result;
}