/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = n + 1;
    
    int* result = (int*)malloc((n + 1) * sizeof(int));
    
    int low = 0;
    int high = n;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            result[i] = low;
            low++;
        } else { // s[i] == 'D'
            result[i] = high;
            high--;
        }
    }
    
    // ตัวสุดท้าย: low == high
    result[n] = low;
    
    return result;
}