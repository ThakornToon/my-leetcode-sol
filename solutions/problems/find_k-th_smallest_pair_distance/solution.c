int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Count pairs with distance <= target using sliding window
int countPairs(int* nums, int numsSize, int target) {
    int count = 0;
    int left = 0;
    
    for (int right = 0; right < numsSize; right++) {
        // Shrink window from left until nums[right] - nums[left] <= target
        while (nums[right] - nums[left] > target) {
            left++;
        }
        // All pairs from left to right-1 with right have distance <= target
        count += (right - left);
    }
    
    return count;
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int left = 0;
    int right = nums[numsSize - 1] - nums[0];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countPairs(nums, numsSize, mid);
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}