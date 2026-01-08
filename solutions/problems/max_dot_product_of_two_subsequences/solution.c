int max(int a, int b) {
    return a > b ? a : b;
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // dp[i][j] = dot product ที่ดีที่สุดเมื่อพิจารณา nums1 ยาว i และ nums2 ยาว j
    int** dp = (int**)malloc((nums1Size + 1) * sizeof(int*));
    for (int i = 0; i <= nums1Size; i++) {
        dp[i] = (int*)malloc((nums2Size + 1) * sizeof(int));
        for (int j = 0; j <= nums2Size; j++) {
            dp[i][j] = INT_MIN / 2;  // ใช้ INT_MIN/2 เพื่อป้องกัน overflow
        }
    }

    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1], 
            max(dp[i - 1][j], 
            max(dp[i][j - 1], nums1[i - 1] * nums2[j - 1])));
        }
    }

    int res = dp[nums1Size][nums2Size];

    // Free memory
    for (int i = 0; i <= nums1Size; i++) {
        free(dp[i]);
    }
    free(dp);

    return res;
}