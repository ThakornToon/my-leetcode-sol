class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);

        // เก็บ index i มาเรียงตามค่า arr[i] น้อยไปมาก
        vector<int> indices(n);
        
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        // เรียง index ตามค่า arr
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        // เริ่ม dp จากค่าน้อยสุด
        for (int idx : indices) {
            int i = idx;
            
            // กระโดดไปทางขวา
            for (int j = i + 1; j <= i + d && j < n; j++) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            
            // กระโดดไปทางซ้าย
            for (int j = i - 1; j >= i - d && j >= 0; j--) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};