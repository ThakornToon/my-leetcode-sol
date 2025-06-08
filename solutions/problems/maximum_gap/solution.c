int maximumGap(int* nums, int numsSize) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (max_val < nums[i]) {
            max_val = nums[i];
        }
        if (min_val > nums[i]) {
            min_val = nums[i];
        }
    }
    if (min_val == max_val) {
        return 0;
    }
    int bucket_size = 1;
    if ((max_val - min_val) / (numsSize - 1) != 0) { // เมื่อเรียงลำดับตัวเลข n ตัวจะมีช่องว่างระหว่างตัวเลขที่อยู่ติดกันทั้งหมด n-1 ช่อง (average gap)
        bucket_size = (max_val - min_val) / (numsSize - 1);
    }
    int bucket_num = (max_val - min_val) / bucket_size + 1;
    int* bucketLargest = (int*)malloc(bucket_num * sizeof(int));
    int* bucketSmallest = (int*)malloc(bucket_num * sizeof(int));
    for (int i = 0; i < bucket_num; i++) {
        bucketLargest[i] = INT_MIN;
        bucketSmallest[i] = INT_MAX;
    }
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] - min_val) / bucket_size;
        if (bucketLargest[index] < nums[i]) {
            bucketLargest[index] = nums[i];
        }
        if (bucketSmallest[index] > nums[i]) {
            bucketSmallest[index] = nums[i];
        }
    }

    int max_gap = 0;
    int i = 0;
    int j = 1;
    while (j < bucket_num) {
        if (bucketLargest[j] == INT_MIN) {
            j++;
        } else if (bucketLargest[i] == INT_MIN) {
            i++;
        } else {
            if (max_gap < bucketSmallest[j] - bucketLargest[i]) {
                max_gap = bucketSmallest[j] - bucketLargest[i];
            }
            i++;
            j++;
        }
    }
    free(bucketLargest);
    free(bucketSmallest);
    return max_gap;
}