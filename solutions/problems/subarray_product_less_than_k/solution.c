int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0; // Since all numbers are positive
    
    int count = 0;
    int product = 1;
    int left = 0;
    
    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];
        
        // Shrink window from left while product >= k
        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
        }
        
        // Number of new subarrays ending at right
        count += (right - left + 1);
    }
    
    return count;
}