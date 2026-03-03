#define MIN(a, b) ((a) < (b) ? (a) : (b))

int palindromePartition(char* s, int k) {
    int n = strlen(s);
    
    // คำนวณ cost[i][j] - จำนวนการเปลี่ยนเพื่อทำให้ s[i..j] เป็น palindrome
    int** cost = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        cost[i] = (int*)malloc(n * sizeof(int));
        memset(cost[i], 0, n * sizeof(int));
    }
    
    // คำนวณ cost สำหรับทุก substring
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i + length <= n; i++) {
            int j = i + length - 1;
            // ถ้าตัวแรกและตัวสุดท้ายต่างกัน ต้องเปลี่ยน 1 ตัว
            // บวกกับ cost ของ substring ข้างใน (i+1 ถึง j-1)
            cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
        }
    }
    
    // DP array: dp[i][p] = min cost สำหรับ s[0..i] แบ่งเป็น p ส่วน
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
        for (int p = 0; p <= k; p++) {
            dp[i][p] = INT_MAX;
        }
    }
    
    // Base case: แบ่งเป็น 1 ส่วน = cost[0][i]
    for (int i = 0; i < n; i++) {
        dp[i][1] = cost[0][i];
    }
    
    // คำนวณ DP ค่อยๆแบ่ง p ส่วนจนครบ k
    for (int p = 2; p <= k; p++) {
        for (int i = p - 1; i < n; i++) {  // ต้องมีอย่างน้อย p ตัวอักษร
            for (int j = p - 2; j < i; j++) {  // j คือตำแหน่งสุดท้ายของส่วนก่อนหน้า
                // substr 0..j..=i ส่วนสุดท้ายคือ j..=i 
                if (dp[j][p - 1] != INT_MAX) {
                    dp[i][p] = MIN(dp[i][p], dp[j][p - 1] + cost[j + 1][i]);
                }
            }
        }
    }
    
    // แบ่งถึงตำแหน่งสุดท้ายครบ k
    int result = dp[n - 1][k];
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(cost[i]);
        free(dp[i]);
    }
    free(cost);
    free(dp);
    
    return result;
}