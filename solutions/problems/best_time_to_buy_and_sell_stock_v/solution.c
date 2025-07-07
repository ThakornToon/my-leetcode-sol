long long max(long long a, long long b) {
    return (a >= b) ? a : b;
}

long long min(long long a, long long b) {
    return (a <= b) ? a : b;
}

void swap(long long*** a, long long*** b) {
    long long** temp = *a;
    *a = *b;
    *b = temp;
}

// Optimize space bottom up
long long maximumProfit(int* prices, int pricesSize, int k) {
    /* 
    dp[x][y][z] แบ่งพิจารณาเป็น curr, prev 
    พิจารณาตั้งแต่วันที่ 1 จนถึง curr โดยเหลือการดำเนินการ y ครั้งและมีสถานะ z จะได้กำไรเท่าไร
    z = 0 ว่าง
    z = 1 อยู่ระหว่างช่วง buy
    z = 2 อยู่ระหว่างช่วง short sell
    */
    long long** prev = (long long**)malloc((k + 1) * sizeof(long long*));
    long long** curr = (long long**)malloc((k + 1) * sizeof(long long*));
    for (int i = 0; i <= k; i++) {
        prev[i] = (long long*)malloc(3 * sizeof(long long));
        curr[i] = (long long*)malloc(3 * sizeof(long long));
        for (int j = 0; j < 3; j++) {
            prev[i][j] = INT_MIN;
        }
    }
    // วันที่ 0 ไว้พิจารณาในวันที่ 1 ต่อ
    for (int i = 0; i <= k; i++){
        prev[i][0] = 0;
    }

    // เริ่มจากวันที่ 0 เหลือการดำเนินการ k ครั้งและมีสถานะว่าง
    for (int i = 0; i < pricesSize; i++) {
        for (int j = k; j >= 0; j--) {
            // State 0: ไม่ทำอะไร, พิจารณาสถานะ buy/sell จากเมื่อวานมาจบในวันนี้
            curr[j][0] = prev[j][0];
            curr[j][0] = max(curr[j][0], prev[j][1] + prices[i]); // จบ buy
            curr[j][0] = max(curr[j][0], prev[j][2] - prices[i]); // จบ short sell

            // States 1 กับ 2: ค้างไว้จากอดีต
            curr[j][1] = prev[j][1]; 
            curr[j][2] = prev[j][2];
            if (j < k) { 
                // State 1: พิจารณาจาก state 0 เริ่มเข้ามา states 1
                curr[j][1] = max(prev[j][1], prev[j + 1][0] - prices[i]);
                // State 2: พิจารณาจาก state 0 เริ่มเข้ามา states 2
                curr[j][2] = max(prev[j][2], prev[j + 1][0] + prices[i]);
            } 
        }
        swap(&prev, &curr); // สลับ pointer
    }
    long long ans = prev[0][0];
    for (int i = 0; i <= k; i++) {
        free(prev[i]);
        free(curr[i]);
    }
    free(curr);
    free(prev);
    return ans; // วันที่ n เหลือการดำเนินการ 0 ครั้งและมีสถานะว่าง
}
