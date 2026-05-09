bool winnerSquareGame(int n) {
    // dp[i] ว่าเมื่อ n = i คนเริ่มหยิบก่อนจะชนะได้ไหม
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    
    for (int i = 1; i <= n; i++) {
        // ลองทุก square number ที่ <= i
        for (int j = 1; j * j <= i; j++) {
            // ถ้ามีการเดินที่ทำให้อีกฝ่ายแพ้ (dp[i - j*j] == false)
            if (!dp[i - j * j]) {
                dp[i] = true;
                break;
            }
        }
        // ถ้าไม่พบการเดินที่ชนะ dp[i] จะเป็น false (ค่าเริ่มต้น)
    }
    
    bool result = dp[n];
    free(dp);
    return result;
}