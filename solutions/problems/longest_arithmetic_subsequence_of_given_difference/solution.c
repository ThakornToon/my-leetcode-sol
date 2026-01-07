#define MAX_VAL 10000
#define MIN_VAL -10000
#define OFFSET 20000  // เพื่อให้ index ไม่ติดลบ
#define SIZE 40001    // [-20000, 20000]
// arr[i] อยู่ในช่วง [-10^4, 10^4]
// เราจะขยายช่วงเพื่อรองรับการคำนวณ prev = num - difference

int longestSubsequence(int* arr, int arrSize, int difference) {
    // dp[x] = ความยาวของลำดับย่อยที่ลงท้ายด้วยค่า x
    int* dp = (int*)calloc(SIZE, sizeof(int));
    
    int maxLength = 0;
    
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        
        // คำนวณค่าก่อนหน้า
        int prev = num - difference;
        
        int prevIndex = prev + OFFSET;
        int currentIndex = num + OFFSET;
        
        if (dp[prevIndex] > 0) {
            // ถ้ามีลำดับที่ลงท้ายด้วย prev อยู่แล้ว
            dp[currentIndex] = dp[prevIndex] + 1;
        } else {
            // เริ่มลำดับใหม่
            dp[currentIndex] = 1;
        }
        
        // อัพเดทค่าสูงสุด
        if (dp[currentIndex] > maxLength) {
            maxLength = dp[currentIndex];
        }
    }
    
    free(dp);
    return maxLength;
}