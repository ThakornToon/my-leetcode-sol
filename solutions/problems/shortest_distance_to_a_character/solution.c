/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    
    // เริ่มต้นด้วยค่าที่ใหญ่ที่สุด
    for (int i = 0; i < n; i++) {
        result[i] = INT_MAX;
    }
    
    // Pass 1: ซ้ายไปขวา
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            prev = i;
        }
        if (prev != -1) {
            result[i] = i - prev;
        }
    }
    
    // Pass 2: ขวาไปซ้าย
    prev = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) {
            prev = i;
        }
        if (prev != -1) {
            int dist = prev - i;
            if (dist < result[i]) {
                result[i] = dist;
            }
        }
    }
    
    return result;
}