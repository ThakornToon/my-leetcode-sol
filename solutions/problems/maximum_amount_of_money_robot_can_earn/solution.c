#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_K 3

int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    int m = coinsSize;
    int n = coinsColSize[0];
    
    // dp[i][j][k] = เงินสูงสุดถึง (i,j) โดยใช้ neutralize k ครั้ง
    int*** dp = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc(MAX_K * sizeof(int));
            for (int k = 0; k < MAX_K; k++) {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    
    // เริ่มต้นที่ (0,0)
    int val = coins[0][0];
    if (val >= 0) {
        dp[0][0][0] = val;
    } else {
        // ไม่ neutralize
        dp[0][0][0] = val;
        // neutralize (ถ้า val < 0)
        if (MAX_K > 1) {
            dp[0][0][1] = 0;
        }
    }
    
    // เติมแถวแรก
    for (int j = 1; j < n; j++) {
        int currVal = coins[0][j];
        for (int k = 0; k < MAX_K; k++) {
            if (dp[0][j-1][k] == INT_MIN) continue;
            
            if (currVal >= 0) {
                dp[0][j][k] = MY_MAX(dp[0][j][k], dp[0][j-1][k] + currVal);
            } else {
                // ไม่ neutralize
                dp[0][j][k] = MY_MAX(dp[0][j][k], dp[0][j-1][k] + currVal);
                // neutralize (ถ้ายังมี neutralize เหลือ)
                if (k + 1 < MAX_K) {
                    dp[0][j][k+1] = MY_MAX(dp[0][j][k+1], dp[0][j-1][k]);
                }
            }
        }
    }
    
    // เติมคอลัมน์แรก
    for (int i = 1; i < m; i++) {
        int currVal = coins[i][0];
        for (int k = 0; k < MAX_K; k++) {
            if (dp[i-1][0][k] == INT_MIN) continue;
            
            if (currVal >= 0) {
                dp[i][0][k] = MY_MAX(dp[i][0][k], dp[i-1][0][k] + currVal);
            } else {
                // ไม่ neutralize
                dp[i][0][k] = MY_MAX(dp[i][0][k], dp[i-1][0][k] + currVal);
                // neutralize
                if (k + 1 < MAX_K) {
                    dp[i][0][k+1] = MY_MAX(dp[i][0][k+1], dp[i-1][0][k]);
                }
            }
        }
    }
    
    // DP สำหรับเซลล์ที่เหลือ
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int currVal = coins[i][j];
            
            for (int k = 0; k < MAX_K; k++) {
                int fromTop = dp[i-1][j][k];
                int fromLeft = dp[i][j-1][k];
                int bestPrev = MY_MAX(fromTop, fromLeft);
                
                if (bestPrev == INT_MIN) continue;
                
                if (currVal >= 0) {
                    dp[i][j][k] = MY_MAX(dp[i][j][k], bestPrev + currVal);
                } else {
                    // ค่าลบ: สองทางเลือก
                    // 1. ไม่ neutralize: เอา bestPrev + ค่าลบ
                    dp[i][j][k] = MY_MAX(dp[i][j][k], bestPrev + currVal);
                    // 2. neutralize: ใช้ neutralize 1 ครั้ง ไม่บวกค่าลบ
                    if (k + 1 < MAX_K) {
                        dp[i][j][k+1] = MY_MAX(dp[i][j][k+1], bestPrev);
                    }
                }
            }
        }
    }
    
    // หาค่าสูงสุดที่ (m-1, n-1) สำหรับ k = 0,1,2
    int result = INT_MIN;
    for (int k = 0; k < MAX_K; k++) {
        result = MY_MAX(result, dp[m-1][n-1][k]);
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    
    return result;
}