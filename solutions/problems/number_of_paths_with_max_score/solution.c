

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MOD 1000000007
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// โครงสร้างสำหรับเก็บผลลัพธ์ของแต่ละ cell
typedef struct {
    int score;   // คะแนนสูงสุดถึง cell นี้
    int count;   // จำนวนเส้นทางที่ให้คะแนนสูงสุด
} Cell;

int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){
    int n = boardSize;
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // สร้าง DP table
    Cell*** dp = (Cell***)malloc(n * sizeof(Cell**));
    for (int i = 0; i < n; i++) {
        dp[i] = (Cell**)malloc(n * sizeof(Cell*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (Cell*)malloc(sizeof(Cell));
            dp[i][j]->score = -1;  // -1 หมายถึงไม่สามารถเข้าถึงได้
            dp[i][j]->count = 0;
        }
    }
    
    // เริ่มต้นที่จุด S (bottom-right)
    dp[n-1][n-1]->score = 0;
    dp[n-1][n-1]->count = 1;
    
    // วนลูปจากล่างขึ้นบน, ขวาไปซ้าย
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // ข้ามถ้าเป็นอุปสรรคหรือยังไม่มีคะแนน
            if (board[i][j] == 'X' || dp[i][j]->score == -1) {
                continue;
            }
            
            // คะแนนของ cell ปัจจุบัน (ยกเว้น S และ E)
            int currentScore = 0;
            if (board[i][j] >= '0' && board[i][j] <= '9') {
                currentScore = board[i][j] - '0';
            }
            
            // ลองเคลื่อนที่ไป 3 ทิศทาง: ซ้าย, บน, ซ้าย-บน
            int dirs[3][2] = {{0, -1}, {-1, 0}, {-1, -1}};
            
            for (int d = 0; d < 3; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                
                // ตรวจสอบขอบเขต
                if (ni < 0 || nj < 0) continue;
                
                // คำนวณคะแนนใหม่
                int newScore = dp[i][j]->score + currentScore;
                
                // ถ้ายังไม่เคยเข้าถึง cell นี้
                if (dp[ni][nj]->score == -1) {
                    dp[ni][nj]->score = newScore;
                    dp[ni][nj]->count = dp[i][j]->count;
                }
                // ถ้าเจอคะแนนที่เท่ากัน
                else if (newScore == dp[ni][nj]->score) {
                    dp[ni][nj]->count = (dp[ni][nj]->count + dp[i][j]->count) % MOD;
                }
                // ถ้าเจอคะแนนที่มากกว่า
                else if (newScore > dp[ni][nj]->score) {
                    dp[ni][nj]->score = newScore;
                    dp[ni][nj]->count = dp[i][j]->count;
                }
            }
        }
    }
    
    // ตรวจสอบผลลัพธ์ที่จุด E (0,0)
    if (dp[0][0]->score == -1) {
        result[0] = 0;
        result[1] = 0;
    } else {
        result[0] = dp[0][0]->score;
        result[1] = dp[0][0]->count % MOD;
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    
    return result;
}