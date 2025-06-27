/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int current, int n, int* result, int* index) {
    if (current > n) return;
    
    // เพิ่มค่าปัจจุบันลงในอาร์เรย์ผลลัพธ์
    result[(*index)++] = current;
    
    // เรียกซ้ำสำหรับตัวเลขถัดไป (0-9)
    for (int i = 0; i <= 9; ++i) {
        int next = current * 10 + i;
        if (next > n) return;
        dfs(next, n, result, index);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;
    
    // เรียกใช้ DFS สำหรับตัวเลข 1-9
    for (int i = 1; i <= 9; ++i) {
        dfs(i, n, result, &index);
    }
    
    return result;
}