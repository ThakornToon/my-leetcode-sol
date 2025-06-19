// F(k) = F(k-1) + sum - n * nums[n-k]
int maxRotateFunction(int* nums, int numsSize) {
    int sum = 0;
    int f = 0;
    
    // คำนวณ sum และ F(0)
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        f += i * nums[i];
    }
    
    int max_f = f;
    
    // คำนวณ F(k) สำหรับ k = 1 ถึง n-1
    for (int k = 1; k < numsSize; k++) {
        f = f + sum - numsSize * nums[numsSize - k];
        if (f > max_f) {
            max_f = f;
        }
    }
    
    return max_f;
}