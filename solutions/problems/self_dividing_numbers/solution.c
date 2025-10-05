/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelfDividing(int num) {
    int n = num;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0 || num % digit != 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* result = malloc((right - left + 1) * sizeof(int));
    *returnSize = 0;
    
    for (int i = left; i <= right; i++) {
        if (isSelfDividing(i)) {
            result[(*returnSize)++] = i;
        }
    }
    
    return result;
}