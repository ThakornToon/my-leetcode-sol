/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    
    // ตัวสุดท้ายให้เป็น -1
    int maxRight = -1;
    
    // วนจากขวาไปซ้าย
    for (int i = arrSize - 1; i >= 0; i--) {
        int current = arr[i];           // เก็บค่าปัจจุบันไว้ก่อน
        arr[i] = maxRight;               // แทนที่ด้วยค่ามากที่สุดทางขวา
        if (current > maxRight) {        // อัปเดต maxRight
            maxRight = current;
        }
    }
    
    return arr;
}