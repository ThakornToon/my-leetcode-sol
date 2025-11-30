/* 
Start with 0 points.
Each turn: draw a random number from 1 to maxPts (equal chance).
Add that number to your score.
Stop when your score reaches k or more.
We want the probability that when you stop, your final score is n or less.
dp[i] = (dp[i-1] + dp[i-2] + ... + dp[i-maxPts]) / maxPts.
*/
double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k + maxPts) {
        return 1.0;
    }
    
    double* dp = (double*)malloc((n + 1) * sizeof(double));
    for (int i = 0; i <= n; i++) {
        dp[i] = 0.0;
    }
    dp[0] = 1.0;
    
    double windowSum = 1.0;
    double result = 0.0;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = windowSum / maxPts;
        
        if (i < k) {
            windowSum += dp[i];
        } else {
            result += dp[i];
        }
        
        if (i >= maxPts) {
            windowSum -= dp[i - maxPts];
        }
    }
    
    free(dp);
    return result;
}