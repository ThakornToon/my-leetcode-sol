/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Binary search ใน sorted unique array
int binarySearch(int* unique, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (unique[mid] == target)
            return mid;
        else if (unique[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    if (arrSize == 0) return NULL;

    // 1. คัดลอก array และเรียงลำดับ
    int* sorted = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        sorted[i] = arr[i];
    }
    qsort(sorted, arrSize, sizeof(int), cmp);

    // 2. สร้าง array ของ unique values
    int* unique = (int*)malloc(arrSize * sizeof(int));
    int uniqueSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            unique[uniqueSize++] = sorted[i];
        }
    }

    // 3. สร้าง result array
    int* result = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        int pos = binarySearch(unique, uniqueSize, arr[i]);
        result[i] = pos + 1; // rank เริ่มที่ 1
    }

    free(sorted);
    free(unique);
    return result;
}