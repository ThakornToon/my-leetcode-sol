class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size(), m = arr2.size();
        
        // dp[i][j] = min ops ที่ทำให้ arr1[0..i] strictly increasing 
        // โดย arr1[i] = arr2[j] (หรือไม่เปลี่ยนถ้า j == m)
        // j = m หมายถึงไม่แทนที่ (ใช้ค่าเดิมจาก arr1[i])
        vector<vector<int>> dp(n, vector<int>(m + 1, INT_MAX));
        
        // กรณี i = 0 (ตำแหน่งแรก)
        // ไม่เปลี่ยน: ใช้ค่า arr1[0]
        dp[0][m] = 0;
        
        // เปลี่ยน: ใช้ค่า arr2[j] ใดๆ
        for (int j = 0; j < m; j++) {
            dp[0][j] = 1;  // เปลี่ยน 1 ครั้ง
        }
        
        for (int i = 1; i < n; i++) {
            // Case 1: ไม่เปลี่ยน arr1[i]
            if (arr1[i] > arr1[i-1]) {
                dp[i][m] = min(dp[i][m], dp[i-1][m]);
            }
            for (int j = 0; j < m; j++) {
                if (arr1[i] > arr2[j] && dp[i-1][j] != INT_MAX) {
                    dp[i][m] = min(dp[i][m], dp[i-1][j]);
                }
            }
        
            // prefixMin[k] = min(dp[i-1][j]) สำหรับ j <= k หากรณีดีที่สุดก่อนหน้าเพื่อลดการคิด Case 2
            vector<int> prefixMin(m, INT_MAX);
            int minSoFar = INT_MAX;
            for (int j = 0; j < m; j++) {
                minSoFar = min(minSoFar, dp[i-1][j]);
                prefixMin[j] = minSoFar;
            }

            // Case 2: เปลี่ยน arr1[i] เป็น arr2[k]
            for (int k = 0; k < m; k++) {
                // จากไม่เปลี่ยนก่อนหน้า (ใช้ arr1[i-1])
                if (arr2[k] > arr1[i-1] && dp[i-1][m] != INT_MAX) {
                    dp[i][k] = min(dp[i][k], dp[i-1][m] + 1);
                }
                
                // จากเปลี่ยนก่อนหน้า (ใช้ arr2[j])
                // ต้องหา arr2[j] ที่ < arr2[k]
                // เราสามารถ binary search หา j ที่ arr2[j] < arr2[k]
                // หรือใช้ prefix minimum
                if (k > 0 && prefixMin[k - 1] != INT_MAX) {
                    dp[i][k] = min(dp[i][k], prefixMin[k - 1] + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int j = 0; j <= m; j++) {
            result = min(result, dp[n-1][j]);
        }
        
        return result == INT_MAX ? -1 : result;
    }
};