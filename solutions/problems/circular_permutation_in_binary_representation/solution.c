/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize){
    *returnSize = 1 << n;
    int* gray = (int*)malloc(*returnSize * sizeof(int));
    
    // สร้าง gray code
    for (int i = 0; i < *returnSize; i++) {
        gray[i] = i ^ (i >> 1);
    }
    
    // หาตำแหน่งของ start
    int startIndex = 0;
    for (int i = 0; i < *returnSize; i++) {
        if (gray[i] == start) {
            startIndex = i;
            break;
        }
    }
    
    // สร้าง result โดย rotate
    int* result = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = gray[(startIndex + i) % *returnSize];
    }
    
    free(gray);
    return result;
}