/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    // ใช้ counting sort (ค่าสูงสุด 1000)
    int count[1001] = {0};
    *returnSize = arr1Size;
    int* result = (int*)malloc(arr1Size * sizeof(int));
    
    // นับความถี่
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }
    
    int idx = 0;
    
    // ใส่ตามลำดับใน arr2
    for (int i = 0; i < arr2Size; i++) {
        int num = arr2[i];
        while (count[num] > 0) {
            result[idx++] = num;
            count[num]--;
        }
    }
    
    // ใส่ที่เหลือเรียงลำดับ
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[idx++] = i;
            count[i]--;
        }
    }
    
    return result;
}