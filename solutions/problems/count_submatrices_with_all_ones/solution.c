#define MIN(a, b) ((a) < (b) ? (a) : (b))

int numSubmat(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    
    // สร้าง dp array ขนาด m x n
    // dp[i][j] = จำนวน 1 ติดกันทางขวา (consecutive ones) ในแถว i เริ่มจาก column j
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }
    
    // คำนวณ consecutive ones ในแนวนอน (ทางขวา)
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                count++;
                dp[i][j] = count;
            } else {
                count = 0;
            }
        }
    }
    
    int result = 0;
    
    // นับ submatrix ทั้งหมด
    // สำหรับแต่ละ cell (i,j) ที่เป็น 1 ให้ลองขึ้นไปด้านบน (ทุกแถวที่อยู่เหนือขึ้นไป) และนับจำนวน submatrix ที่มี (i,j) เป็นมุมล่างขวา
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) continue;
            
            int minWidth = INT_MAX;
            // ขึ้นไปด้านบนตั้งแต่แถว i ลงไปถึงแถว 0
            for (int k = i; k >= 0; k--) {
                // dp[k][j] คือจำนวน 1 ติดกันในแถว k เริ่มที่ column j
                if (dp[k][j] == 0) break;
                
                minWidth = MIN(minWidth, dp[k][j]);
                result += minWidth;
                // result += minWidth หมายถึง:
                // - minWidth คือความกว้างสูงสุดที่ความสูง (i-k+1) นี้
                // - แต่ละความกว้าง 1..minWidth ก็เป็น submatrix ที่ถูกต้อง
                // - ดังนั้นจำนวน submatrix ที่เพิ่ม = minWidth
            }
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}