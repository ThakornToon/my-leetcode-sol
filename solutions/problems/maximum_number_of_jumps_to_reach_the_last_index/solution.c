#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumJumps(int* nums, int numsSize, int target) {
    // dp[i] = จำนวนกระโดดสูงสุดที่ไปถึง index i
    int* dp = (int*)malloc(numsSize * sizeof(int));
    
    // เริ่มต้นทุกค่าด้วย -1 (หมายถึงไปไม่ถึง)
    for (int i = 0; i < numsSize; i++) {
        dp[i] = -1;
    }
    
    // จุดเริ่มต้น: index 0 มี 0 ครั้ง (ยังไม่กระโดด)
    dp[0] = 0;
    
    // พิจารณาแต่ละตำแหน่งเป้าหมาย j (จากซ้ายไปขวา)
    for (int j = 1; j < numsSize; j++) {
        // หา i ที่กระโดดจาก i มาที่ j ได้
        for (int i = 0; i < j; i++) {
            // ถ้าไปถึง i ได้ และสามารถกระโดดจาก i ไป j ได้
            if (dp[i] != -1 && abs(nums[i] - nums[j]) <= target) {
                dp[j] = MAX(dp[j], dp[i] + 1);
            }
        }
    }
    
    int result = dp[numsSize - 1];
    free(dp);
    return result;
}