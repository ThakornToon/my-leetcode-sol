class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // suffixSum[i] = ผลรวมตั้งแต่ i จนถึง n - 1
        vector<int> suffixSum(n + 1, 0);
        
        // คำนวณ suffix sum
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // dp[i][M] = คะแนนสูงสุดที่ผู้เล่นปัจจุบันจะได้จาก piles[i..n-1] เมื่อ M = M
        // M จะเพิ่มขึ้นเรื่อยๆ ถ้า M > n ก็หยิบได้แค่ n กอง (ไม่มีกองเกิน n)
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        
        // คิดจากจำนวนกองน้อยๆย้อนกลับมา
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                // ลองหยิบ X กองที่เป็นไปได้จาก M ปัจจุบัน
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    // M ของการหยิบครั้งถัดไป
                    int nextM = max(M, X);
                    // คะแนนของผู้เล่นปัจจุบัน = ผลรวมที่หยิบ + (ผลรวมที่เหลือ - คะแนนผู้เล่นถัดไป)
                    int currentTake = suffixSum[i] - suffixSum[i + X];
                    int nextScore = dp[i + X][nextM];
                    dp[i][M] = max(dp[i][M], currentTake + (suffixSum[i + X] - nextScore));
                }
            }
        }
        
        return dp[0][1];
    }
};