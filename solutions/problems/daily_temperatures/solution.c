/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int stackTop = -1;
    
    for (int i = 0; i < temperaturesSize; i++) {
        while (stackTop >= 0 && temperatures[i] > temperatures[stack[stackTop]]) {
            int prevIndex = stack[stackTop];
            stackTop--;
            result[prevIndex] = i - prevIndex;
        }
        stack[++stackTop] = i;
    }
    
    free(stack);
    return result;
}