int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findLHS(int* nums, int numsSize) {    
    // Sort array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int max_length = 0;
    int prev_count = 1;
    int current_count = 1;
    int prev = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            current_count++;
        } else if (nums[i] == nums[i - 1] + 1) {
            prev = nums[i - 1];
            prev_count = current_count;
            current_count = 1;
        } else {
            prev_count = 1;
            current_count = 1;
        }
        
        if (nums[i] == prev + 1) {
            max_length = (prev_count + current_count > max_length) ? 
                         prev_count + current_count : max_length;
        }
    }
    
    return max_length;
}