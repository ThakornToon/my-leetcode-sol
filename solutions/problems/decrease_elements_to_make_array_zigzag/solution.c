int movesToMakeZigzag(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    
    int pattern1 = 0; // nums[0] > nums[1] < nums[2] > ...
    int pattern2 = 0; // nums[0] < nums[1] > nums[2] < ...
    
    for (int i = 0; i < numsSize; i++) {
        int left = (i > 0) ? nums[i-1] : INT_MAX;
        int right = (i < numsSize - 1) ? nums[i+1] : INT_MAX;
        
        int min_neighbor = (left < right) ? left : right;
        int target = min_neighbor - 1;
        
        if (i % 2 == 0) {  // Even index
        // Pattern 2: Odd indices เป็น peaks  
        // ดังนั้น even indices (0,2,4,...) ควรเป็น valleys
            if (nums[i] > target) {
                pattern1 += nums[i] - target;
            }
        } else {  // Odd index
        // Pattern 1: Even indices เป็น peaks
        // ดังนั้น odd indices (1,3,5,...) ควรเป็น valleys
            if (nums[i] > target) {
                pattern2 += nums[i] - target;
            }
        }
    }
    
    return (pattern1 < pattern2) ? pattern1 : pattern2;
}