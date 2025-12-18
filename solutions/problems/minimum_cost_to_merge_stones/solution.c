#define MIN(a, b) ((a) < (b) ? (a) : (b))

int mergeStones(int* stones, int stonesSize, int k) {
    int n = stonesSize;
    
    // ตรวจสอบความเป็นไปได้ในการรวมจนเหลือกองเดียว
    if ((n - 1) % (k - 1) != 0) {
        return -1;
    }
    
    // prefix sum เพื่อคำนวณผลรวมช่วงเร็วๆ
    int* prefix = (int*)malloc((n + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < n; i++) { // รวมหินที่ i ถึง j = prefix[j+1] - prefix[i]
        prefix[i + 1] = prefix[i] + stones[i];
    }
    
    // dp[i][j] = min cost ในการรวม stones[i..j] ให้มีกองน้อยที่สุดเท่าที่เป็นไปได้
    int** dp = (int**)malloc(n * sizeof(int*));
    // set ค่าเริ่มต้น ถ้ามีก้อนเดียวไม่สามารถรวมได้
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    
    // DP จากช่วงสั้นไปยาว
    for (int len = 2; len <= n; len++) {
        // จุดเริ่มต้นในการรวม
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            
            // ลองแบ่งทุกตำแหน่งที่เป็นไปได้ i...m กับ m+1...j ในการรวม
            for (int m = i; m < j; m += k - 1) {
                dp[i][j] = MIN(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }
            
            // ถ้าสามารถ merge เป็น 1 กองได้จะรวมตั้งแต่ i...j (แบ่งส่วนคิดการรวมก่้่่อนย่อยเพื่อหากรณีดีที่สุดก่อนรวมรอบสุดท้ายเป็นก้อนเดียว)
            if ((len - 1) % (k - 1) == 0) {
                dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
    }
    
    int result = dp[0][n - 1];
    
    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    free(prefix);
    
    return result;
}