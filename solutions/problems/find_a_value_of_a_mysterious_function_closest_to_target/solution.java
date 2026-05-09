class Solution {
    private int[][] st;  // st[K][i] = AND เริ่มที่ i ด้วยความยาว 2^k
    private int[] log;  // log[i] = log2(i)

    private void build(int[] arr) {
        int n = arr.length;
        int K = 20;  // 2^20 > 10^6
        st = new int[K][n];
        log = new int[n + 5];
        
        // Build Sparse Table
        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }
        
        for (int k = 1; k < K; k++) {
            int len = 1 << k;
            if (len > n) break;
            for (int i = 0; i + len <= n; i++) {
                // i..=i+2^k -> i..i+2^(k-1) & i+2^(k-1)..i+2^k
                st[k][i] = st[k-1][i] & st[k-1][i + (1 << (k-1))];
            }
        }
        
        // Build LOG table
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
    }
    
    private int rangeAnd(int l, int r) {
        // 2^k = r - l + 1 != ความยาวช่วง (log เราเป็นแบบปัดลง)
        // r = l + 1 + 2^k
        int k = log[r - l + 1];

        // l..=r -> l..l+2^k & r+1-2^k..=r
        return st[k][l] & st[k][r - (1 << k) + 1];
    }

    public int closestToTarget(int[] arr, int target) {
        int n = arr.length;
        build(arr);
        
        int minDiff = Math.abs(arr[0] - target);
        
        // binary search หาค่าที่ใกล้ที่สุดทุกครั้งสำหรับ i ที่เป็นจุดเริ่มต้น
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int andVal = rangeAnd(i, mid);  // AND i..=mid
                int diff = Math.abs(andVal - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                }
                
                if (andVal >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return minDiff;
    }
}