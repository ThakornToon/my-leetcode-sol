class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        Arrays.sort(indices, (a, b) -> arr[a] - arr[b]);
        
        for (int idx : indices) {
            int i = idx;
            
            // กระโดดไปทางขวา
            for (int j = i + 1; j <= i + d && j < n; j++) {
                if (arr[j] >= arr[i]) break;
                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }
            
            // กระโดดไปทางซ้าย
            for (int j = i - 1; j >= i - d && j >= 0; j--) {
                if (arr[j] >= arr[i]) break;
                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }
        }
        
        int result = 0;
        for (int val : dp) {
            result = Math.max(result, val);
        }
        return result;
    }
}