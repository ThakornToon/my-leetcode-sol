/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    
    int index = 0;
    
    // ถ้า n เป็นคี่ ให้ใส่ 0 ไว้ตรงกลาง
    if (n % 2 == 1) {
        result[index++] = 0;
    }
    
    // ใส่คู่ (i, -i) ไปเรื่อยๆ
    for (int i = 1; index < n; i++) {
        result[index++] = i;
        result[index++] = -i;
    }
    
    return result;
}