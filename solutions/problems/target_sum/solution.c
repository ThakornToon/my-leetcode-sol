/*
sum = ผลรวมทั้งหมดของอาร์เรย์
P = ผลรวมของตัวเลขที่ใส่เครื่องหมาย '+'
N = ผลรวมของตัวเลขที่ใส่เครื่องหมาย '-'

จากเงื่อนไขโจทย์:
P + N = sum (เพราะตัวเลขทั้งหมดต้องถูกใช้)
P - N = target (ผลรวมสุดท้ายต้องเท่ากับ target)

2P = sum + target
∴ P = (sum + target) / 2
2N = sum - target
∴ N = (sum - target) / 2

P = (sum + target) / 2:
(sum + target) ต้องเป็นเลขคู่ (หาร 2 ลงตัว)
P ต้องเป็นจำนวนเต็มไม่ติดลบ
P ≤ sum (เพราะ P เป็นสับเซตของตัวเลขทั้งหมด)

หาจำนวนสับเซตที่มีผลรวมเท่ากับ P = (sum + target) / 2
dp[j] = จำนวนวิธีที่จะได้ผลรวม j โดยใช้ตัวเลขบางส่วนจากอาร์เรย์
*/

int findTargetSumWays(int* nums, int numsSize, int target) {
    // Step 1: คำนวณผลรวมทั้งหมด
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    // Step 2: ตรวจสอบเงื่อนไขความเป็นไปได้
    if (abs(target) > sum || (sum + target) % 2 != 0) {
        return 0;
    }
    
    // Step 3: คำนวณ subset sum ที่ต้องการ
    int subsetSum = (sum + target) / 2;
    
    int* dp = (int*)calloc(subsetSum + 1, sizeof(int));
    dp[0] = 1;  // base case: 1 way to get sum 0
    
    // Step 5: ลองหยิบมาดูทีละตัว
    for (int i = 0; i < numsSize; i++) {
        for (int j = subsetSum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    
    int result = dp[subsetSum];
    free(dp);
    return result;
}