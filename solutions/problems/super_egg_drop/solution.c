int superEggDrop(int k, int n) {
    // dp[m][k] = จำนวนชั้นสูงสุดที่ตรวจสอบได้ด้วย m ครั้งและ k ฟอง
    // แต่เราใช้ 1D พอ d[k]
    int* dp = (int*)malloc((k + 1) * sizeof(int));
    
    for (int i = 0; i <= k; i++) {
        dp[i] = 0;  // ด้วย 0 ครั้ง ตรวจสอบได้ 0 ชั้น
    }
    
    int m = 0; // จำนวนครั้ง
    while (dp[k] < n) {
        m++;
        // อัพเดตจากหลังไปหน้าเพื่อไม่ให้เขียนทับ
        for (int i = k; i >= 1; i--) {
            dp[i] = dp[i] + dp[i-1] + 1;
            // dp[i] = (ไข่ไม่แตก) + (ไข่แตก) + 1
        }
    }
    
    free(dp);
    return m;
}