#define max(a, b) ((a) > (b) ? (a) : (b))

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = {0, -1, -1};  // เริ่มต้น: remainder 0 ได้ 0, อื่นยังไม่มี
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int new_dp[3] = {dp[0], dp[1], dp[2]};

        for (int r = 0; r < 3; r++) {
            if (dp[r] != -1) {  // ถ้ามีค่าสำหรับ remainder นี้
                int new_r = (r + num) % 3;
                int new_sum = dp[r] + num;
                
                // อัปเดตถ้าได้ค่ามากกว่า
                if (new_sum > new_dp[new_r]) {
                    new_dp[new_r] = new_sum;
                }
            }
        }
        
        dp[0] = new_dp[0];
        dp[1] = new_dp[1];
        dp[2] = new_dp[2];
    }
    
    return dp[0];  // remainder 0 คือผลรวมที่หารด้วย 3 ลงตัว
}