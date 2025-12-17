#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_DAYS 366  // Day 0 to 365

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    // สร้าง array เพื่อบันทึกว่าวันไหนต้องเดินทาง
    int travel[MAX_DAYS] = {0};
    
    for (int i = 0; i < daysSize; i++) {
        travel[days[i]] = 1;
    }
    
    // DP array: dp[i] = min cost up to day i
    int* dp = (int*)calloc(MAX_DAYS, sizeof(int));
    
    for (int i = 1; i < MAX_DAYS; i++) {
        if (!travel[i]) {
            // ไม่ต้องเดินทางในวันนี้
            dp[i] = dp[i-1];
        } else {
            // ตั๋วจะหมดอายุหลังจบวันที่ i

            // ซื้อตั๋ว 1 วัน
            int cost = dp[i-1] + costs[0];
            
            // ซื้อตั๋ว 7 วัน
            cost = MIN(cost, dp[MAX(0, i-7)] + costs[1]);
            
            // ซื้อตั๋ว 30 วัน
            cost = MIN(cost, dp[MAX(0, i-30)] + costs[2]);
            
            dp[i] = cost;
        }
    }
    
    int result = dp[365];
    free(dp);
    return result;
}