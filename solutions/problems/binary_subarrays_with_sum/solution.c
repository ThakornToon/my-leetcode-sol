int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    // สร้าง hash map สำหรับนับ frequency ของ prefix sum
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    count[0] = 1;  // prefix sum = 0 มี 1 วิธี (เริ่มต้น)
    
    int prefixSum = 0;
    int result = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        
        // เราต้องการหา count[prefixSum - goal]
        // เพราะถ้า prefixSum[current] - prefixSum[previous] = goal
        // แสดงว่า subarray จาก previous+1 ถึง current มี sum = goal
        int target = prefixSum - goal;
        if (target >= 0) {
            result += count[target];
        }
        
        count[prefixSum]++;
    }
    
    free(count);
    return result;
}