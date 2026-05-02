#define MAX(a, b) ((a) > (b) ? (a) : (b))

int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));  // เก็บตำแหน่ง dp ก่อนหน้า
    int front = 0, rear = 0;
    int result = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        // หาค่า max จาก deque
        int maxPrev = (front < rear) ? dp[deque[front]] : 0;
        
        // คำนวณ dp[i]
        dp[i] = nums[i] + MAX(maxPrev, 0);
        
        // อัปเดต result
        if (dp[i] > result) result = dp[i];
        
        // ลบ elements ที่อยู่นอกช่วง window
        while (front < rear && deque[front] < i - k + 1) {
            front++;
        }
        
        // ลบ elements ที่มีค่าน้อยกว่า dp[i] (รักษา deque ให้ลดหลั่น)
        while (front < rear && dp[deque[rear - 1]] <= dp[i]) {
            rear--;
        }
        
        // เพิ่ม element ปัจจุบัน
        deque[rear++] = i;
    }
    
    free(dp);
    free(deque);
    return result;
}