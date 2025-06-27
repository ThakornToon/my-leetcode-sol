/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int value;
    int original_index;
} NumWithIndex;

void mergeSort(NumWithIndex* nums, NumWithIndex* temp, int* counts, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(nums, temp, counts, left, mid);
    mergeSort(nums, temp, counts, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    int right_count = 0;
    
    while (i <= mid && j <= right) {
        if (nums[i].value > nums[j].value) {
            right_count++;
            temp[k++] = nums[j++];
        } else {
            counts[nums[i].original_index] += right_count;
            temp[k++] = nums[i++];
        }
    }
    
    while (i <= mid) {
        counts[nums[i].original_index] += right_count;
        temp[k++] = nums[i++];
    }
    
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    for (int idx = left; idx <= right; idx++) {
        nums[idx] = temp[idx];
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;    
    NumWithIndex* nums_with_index = (NumWithIndex*)malloc(numsSize * sizeof(NumWithIndex));
    int* counts = (int*)calloc(numsSize, sizeof(int));
    NumWithIndex* temp = (NumWithIndex*)malloc(numsSize * sizeof(NumWithIndex));
    
    for (int i = 0; i < numsSize; i++) {
        nums_with_index[i] = (NumWithIndex){nums[i], i};
    }
    
    mergeSort(nums_with_index, temp, counts, 0, numsSize - 1);
    
    free(nums_with_index);
    free(temp);
    
    return counts;
}