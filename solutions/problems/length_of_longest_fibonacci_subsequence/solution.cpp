class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        // dp[j][i] ขนาด N*N = ความยาวของลำดับ Fibonacci ที่ลงท้ายด้วย A[j] และ A[i] 
        vector<vector<int>> dp(n, vector<int>(n, 2)); // ค่าเริ่มต้นคือความยาว 2
        int maxLen = 0;
        
        for (int i = 2; i < n; i++) { // เริ่มดูที่ตัวที่สามเป็นต้นไป
            for (int j = i - 1; j >= 0; j--) {
                int target = arr[i] - arr[j]; // prev2 = new - prev1
                if (target >= arr[j]) break; //  เพราะ arr เรียงลำดับแล้ว
                
                if (index.count(target)) { // หาใน map ว่ามีไหม
                    int k = index[target];
                    dp[j][i] = dp[k][j] + 1; // ต่อลำดับเป็น arr[k], arr[j], arr[i]
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }
        
        return maxLen > 2 ? maxLen : 0;
    }
};