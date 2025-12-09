void merge(int* arr, int left, int mid, int right, int* temp) {
    int i = left, j = mid + 1, k = 0;
    
    // Merge สองส่วนเรียงลำดับ
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    // คัดลอกส่วนที่เหลือจากซ้าย
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    // คัดลอกส่วนที่เหลือจากขวา
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    // คัดลอกกลับไปยังอาร์เรย์เดิม
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(int* arr, int left, int right, int* temp) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    if (numsSize <= 1) return nums;
    
    // สร้าง temporary array หนึ่งครั้งเพื่อ reuse
    int* temp = (int*)malloc(numsSize * sizeof(int));
    
    mergeSort(nums, 0, numsSize - 1, temp);
    
    free(temp);
    return nums;
}