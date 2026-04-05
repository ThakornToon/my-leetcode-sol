/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int strength;  // จำนวน 1 ในแถว
    int index;     // index ของแถว
} Row;

int compare(const void* a, const void* b) {
    Row* rowA = (Row*)a;
    Row* rowB = (Row*)b;
    
    if (rowA->strength != rowB->strength) {
        return rowA->strength - rowB->strength;
    }
    return rowA->index - rowB->index;
}

int countOnes(int* row, int n) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (row[mid] == 1) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int m = matSize;
    int n = matColSize[0];
    
    Row* rows = (Row*)malloc(m * sizeof(Row));
    
    for (int i = 0; i < m; i++) {
        rows[i].strength = countOnes(mat[i], n);
        rows[i].index = i;
    }
    
    qsort(rows, m, sizeof(Row), compare);
    
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = rows[i].index;
    }
    
    free(rows);
    return result;
}