int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen) {
    // สร้าง prefix sum array
    int* prefixSum = (int*)malloc((numsSize + 1) * sizeof(int));
    prefixSum[0] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    // ฟังก์ชันหาผลรวม subarray 
    int getSum(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
    
    int maxSum = 0;
    
    // กรณีที่ 1: firstLen อยู่ก่อน secondLen
    int maxFirst = 0;
    for (int i = firstLen + secondLen - 1; i < numsSize; i++) {
        // อัปเดต max ของ firstLen ที่จบก่อน secondLen
        int firstEnd = i - secondLen;
        int firstStart = firstEnd - firstLen + 1;
        int firstSum = getSum(firstStart, firstEnd);
        if (firstSum > maxFirst) {
            maxFirst = firstSum;
        }
        
        // secondLen เริ่มจาก i - secondLen + 1
        int secondStart = i - secondLen + 1;
        int secondSum = getSum(secondStart, i);
        
        maxSum = (maxFirst + secondSum > maxSum) ? maxFirst + secondSum : maxSum;
    }
    
    // กรณีที่ 2: secondLen อยู่ก่อน firstLen
    int maxSecond = 0;
    for (int i = firstLen + secondLen - 1; i < numsSize; i++) {
        // อัปเดต max ของ secondLen ที่จบก่อน firstLen
        int secondEnd = i - firstLen;
        int secondStart = secondEnd - secondLen + 1;
        int secondSum = getSum(secondStart, secondEnd);
        if (secondSum > maxSecond) {
            maxSecond = secondSum;
        }
        
        // firstLen เริ่มจาก i - firstLen + 1
        int firstStart = i - firstLen + 1;
        int firstSum = getSum(firstStart, i);
        
        maxSum = (maxSecond + firstSum > maxSum) ? maxSecond + firstSum : maxSum;
    }
    
    free(prefixSum);
    return maxSum;
}