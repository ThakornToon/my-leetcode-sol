bool isMonotonic(int* nums, int numsSize) {
    bool inc = true, dec = true;
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] < nums[i+1]) {
            dec = false;
        }
        if (nums[i] > nums[i+1]) {
            inc = false;
        }
        
        // Early exit
        if (!inc && !dec) return false;
    }
    
    return inc || dec;
}