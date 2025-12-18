int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right = 0;
    int zeroCount = 0;
    int maxLen = 0;
    
    while (right < numsSize) {
        // ขยาย window ทางขวา
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        // ถ้ามี 0 มากกว่า k ให้หด window ทางซ้าย
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        
        // อัพเดตความยาว window สูงสุด
        int windowLen = right - left + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
        
        right++;
    }
    
    return maxLen;
}