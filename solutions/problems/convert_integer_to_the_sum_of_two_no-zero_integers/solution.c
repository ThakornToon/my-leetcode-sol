/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันตรวจสอบว่ามีเลข 0 หรือไม่
bool hasZero(int num) {
    if (num == 0) return true;
    
    while (num > 0) {
        if (num % 10 == 0) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int a = 1; a < n; a++) {
        int b = n - a;
        
        if (!hasZero(a) && !hasZero(b)) {
            result[0] = a;
            result[1] = b;
            break;
        }
    }
    
    return result;
}