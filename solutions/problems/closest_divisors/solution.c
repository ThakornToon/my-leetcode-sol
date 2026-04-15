/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestDivisors(int num, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    int minDiff = INT_MAX;
    
    for (int n = num + 1; n <= num + 2; n++) {
        for (int a = (int)sqrt(n); a >= 1; a--) {
            if (n % a == 0) {
                int b = n / a;
                int diff = b - a;
                if (diff < minDiff) {
                    minDiff = diff;
                    result[0] = a;
                    result[1] = b;
                }
                break;
            }
        }
    }
    
    return result;
}