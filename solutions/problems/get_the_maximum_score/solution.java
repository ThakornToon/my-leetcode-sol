class Solution {
    private static final int MOD = 1_000_000_007;
    
    public int maxSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        
        long[] dp1 = new long[n];
        long[] dp2 = new long[m];
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                dp1[i] = (i > 0 ? dp1[i - 1] : 0) + nums1[i];
                i++;
            } 
            else if (nums1[i] > nums2[j]) {
                dp2[j] = (j > 0 ? dp2[j - 1] : 0) + nums2[j];
                j++;
            } 
            else {
                // ค่าที่เท่ากัน
                long best = Math.max(
                    (i > 0 ? dp1[i - 1] : 0),
                    (j > 0 ? dp2[j - 1] : 0)
                );
                dp1[i] = best + nums1[i];
                dp2[j] = best + nums2[j];
                i++;
                j++;
            }
        }
        
        // ส่วนที่เหลือ
        while (i < n) {
            dp1[i] = (i > 0 ? dp1[i - 1] : 0) + nums1[i];
            i++;
        }
        while (j < m) {
            dp2[j] = (j > 0 ? dp2[j - 1] : 0) + nums2[j];
            j++;
        }
        
        long result = Math.max(
            n > 0 ? dp1[n - 1] : 0,
            m > 0 ? dp2[m - 1] : 0
        );
        
        return (int) (result % MOD);
    }
}