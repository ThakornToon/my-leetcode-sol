/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* getStrongest(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    
    // sort array
    qsort(arr, arrSize, sizeof(int), compare);
    
    int median = arr[(arrSize - 1) / 2];
    
    // two pointers: เลือกจากซ้ายและขวา
    int left = 0, right = arrSize - 1;
    int idx = 0;
    
    while (idx < k) {
        int leftDiff = abs(arr[left] - median);
        int rightDiff = abs(arr[right] - median);
        
        if (leftDiff > rightDiff) {
            result[idx++] = arr[left++];
        } else if (leftDiff < rightDiff) {
            result[idx++] = arr[right--];
        } else {
            // ถ้าเท่ากัน ให้เอาค่ามากกว่า
            if (arr[left] > arr[right]) {
                result[idx++] = arr[left++];
            } else {
                result[idx++] = arr[right--];
            }
        }
    }
    
    return result;
}