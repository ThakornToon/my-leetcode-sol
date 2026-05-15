#define MAX_N 101

int memo[MAX_N][MAX_N];
int suffixSum[MAX_N];

int solve(int i, int M, int n) {
    // ถ้าไม่มีกองเหลือ
    if (i >= n) return 0;
    
    // M จะไม่เกิน n เพราะถ้าสามารถหยิบได้ทั้งหมดจะหยิบเลย
    if (i + 2 * M >= n) return suffixSum[i];  
    
    // ถ้ามีการคำนวณไว้แล้ว
    if (memo[i][M] != 0) return memo[i][M];
    
    // เราจะหยิบให้ฝั่งตรงข้ามได้น้อยที่สุด
    int minOpponentStone = INT_MAX;
    
    // ลองหยิบ X กอง (1 <= X <= 2M)
    for (int X = 1; X <= 2 * M && i + X <= n; X++) {
        int nextM = (M > X) ? M : X;  // max(M, X)
        int opponentScore = solve(i + X, nextM, n);
        if (opponentScore < minOpponentStone) {
            minOpponentStone = opponentScore;
        }
    }
    
    // คะแนนของผู้เล่นปัจจุบันที่ทำได้ดีที่สุด = ผลรวมทั้งหมด - คะแนนต่ำสุดที่ผู้เล่นถัดไปจะได้
    memo[i][M] = suffixSum[i] - minOpponentStone;
    return memo[i][M];
}

int stoneGameII(int* piles, int pilesSize) {
    int n = pilesSize;
    
    // Initialize memo to 0
    memset(memo, 0, sizeof(memo));
    
    // Calculate suffix sum
    suffixSum[n - 1] = piles[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + piles[i];
    }
    
    return solve(0, 1, n);
}