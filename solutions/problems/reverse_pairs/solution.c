int mergeAndCount(int* nums, int start, int mid, int end) {
    int count = 0;
    int j = mid + 1;
    
    // นับ Reverse Pairs
    for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    
    // Merge ส่วนที่เรียงแล้ว
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));
    int i = start;
    j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    
    while (j <= end) {
        temp[k++] = nums[j++];
    }
    
    for (int p = 0; p < k; p++) {
        nums[start + p] = temp[p];
    }
    
    free(temp);
    return count;
}

int mergeSort(int* nums, int start, int end) {
    if (start >= end) return 0;
    
    int mid = start + (end - start) / 2;
    int count = 0;
    
    count += mergeSort(nums, start, mid);
    count += mergeSort(nums, mid + 1, end);
    count += mergeAndCount(nums, start, mid, end);
    
    return count;
}

int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}