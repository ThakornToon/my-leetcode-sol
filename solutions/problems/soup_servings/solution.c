double dp[200][200];

double dfs(int a, int b) {
    // Base cases
    if (a <= 0 && b <= 0) return 0.5;  // หมดพร้อมกัน
    if (a <= 0) return 1.0;            // A หมดก่อน
    if (b <= 0) return 0.0;            // B หมดก่อน
    
    // Memoization
    if (dp[a][b] > 0) return dp[a][b];
    
    // 4 choices, each with probability 0.25
    double result = 0.0;
    result += dfs(a - 4, b);
    result += dfs(a - 3, b - 1);
    result += dfs(a - 2, b - 2);
    result += dfs(a - 1, b - 3);
    
    dp[a][b] = result * 0.25;
    return dp[a][b];
}

double soupServings(int n) {
    if (n >= 4800) return 1.0; // จะประมาณได้เป็น 1

    // Convert to servings of 25ml
    int servings = (n + 24) / 25;
    
    // Initialize DP table
    memset(dp, 0, sizeof(dp));
    
    return dfs(servings, servings);
}