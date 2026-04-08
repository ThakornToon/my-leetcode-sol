class Solution {
    private static final int MOD = 1_000_000_007;

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        
        for (int[] q : queries) {
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];
            
            for (int idx = li; idx <= ri; idx += ki) {
                arr[idx] = (arr[idx] * vi) % MOD;
            }
        }
        
        int result = 0;
        for (long val : arr) {
            result ^= (int) val;
        }
        
        return result;
    }
}