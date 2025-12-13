#define MOD 1000000007

int distinctSubseqII(char* s) {
    int n = strlen(s);
    
    // dp[i] = จำนวน subsequence ที่ลงท้ายที่ index i
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    // last[char] = index ล่าสุดของตัวอักษรนั้น
    int last[26];
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
    }
    
    // dp[0] = subsequence ว่าง
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        int idx = c - 'a';
        
        // subsequence ที่ลงท้ายด้วยตัวอักษรปัจจุบัน
        dp[i] = (2 * dp[i - 1]) % MOD;
        
        // ถ้าตัวอักษรนี้เคยปรากฏมาก่อน ให้ลบ subsequence ที่ซ้ำ
        if (last[idx] != -1) {
            dp[i] = (dp[i] - dp[last[idx] - 1] + MOD) % MOD;
        }
        
        // อัปเดตตำแหน่งล่าสุดของตัวอักษร
        last[idx] = i;
    }
    
    int result = dp[n] - 1; // ลบ subsequence ว่าง
    if (result < 0) result += MOD;
    
    free(dp);
    return result % MOD;
}