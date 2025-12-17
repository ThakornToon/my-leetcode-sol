int subarraysDivByK(int* nums, int numsSize, int k) {
    // สร้างอาร์เรย์เก็บ frequency ของ remainder
    int* modCount = (int*)calloc(k, sizeof(int));
    
    // remainder 0 เริ่มต้นมี 1 (prefix sum ว่าง)
    modCount[0] = 1;
    
    int prefixSum = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        
        // หา remainder ให้เป็นบวกเสมอ
        int remainder = prefixSum % k;
        if (remainder < 0) {
            remainder += k;
        }
        
        // เพิ่มจำนวน subarray
        count += modCount[remainder];
        
        // เพิ่ม frequency ของ remainder นี้
        modCount[remainder]++;
    }
    
    free(modCount);
    return count;
}