int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    // เรียงลำดับอาร์เรย์
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 0;
    
    // Fix ด้านที่ใหญ่ที่สุด (c)
    for (int c = numsSize - 1; c >= 2; c--) {
        int a = 0;
        int b = c - 1;
        
        while (a < b) {
            if (nums[a] + nums[b] > nums[c]) {
                // ถ้า nums[a] + nums[b] > nums[c] แล้ว
                // nums[a+1] + nums[b] > nums[c], nums[a+2] + nums[b] > nums[c], ...
                count += (b - a);
                b--;
            } else {
                a++;
            }
        }
    }
    
    return count;
}