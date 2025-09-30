/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    int left = 1, right = n;
    int index = 0;
    
    // สร้าง k-1 ความต่างแรกโดยสลับระหว่างสูงและต่ำ
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            result[index++] = left++;
        } else {
            result[index++] = right--;
        }
    }
    
    // เติมส่วนที่เหลือเรียงตามลำดับ
    if (k % 2 == 1) {
        // ถ้า k เป็นคี่ -> เติมจากซ้ายไปขวา
        while (index < n) {
            result[index++] = left++;
        }
    } else {
        // ถ้า k เป็นคู่ -> เติมจากขวาไปซ้าย
        while (index < n) {
            result[index++] = right--;
        }
    }
    
    return result;
}