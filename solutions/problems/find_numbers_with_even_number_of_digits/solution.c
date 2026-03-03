int findNumbers(int* nums, int numsSize) {
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int digitCount = 0;
        
        // นับจำนวนหลักโดยการหารด้วย 10 ไปเรื่อยๆ
        while (num > 0) {
            digitCount++;
            num /= 10;
        }
        
        // ถ้าจำนวนหลักเป็นเลขคู่
        if (digitCount % 2 == 0) {
            count++;
        }
    }
    
    return count;
}