#define MIN(a, b) ((a) < (b) ? (a) : (b))

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minDistance(int* houses, int housesSize, int k) {
    // sort houses ตำแหน่งน้อยไปมาก
    qsort(houses, housesSize, sizeof(int), compare);
    int n = housesSize;
    
    // cost[i][j] = min total distance for houses[i..=j] with 1 mailbox
    // precompute ให้คิดได้ง่ายขึ้น
    int** cost = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        cost[i] = (int*)calloc(n, sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int median = houses[(i + j) / 2];
            int total = 0;
            for (int t = i; t <= j; t++) {
                total += abs(houses[t] - median);
            }
            cost[i][j] = total;
        }
    }
    
    // dp[i][k] = min distance for first i+1 houses (0..=i) with k mailboxes
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
        for (int t = 0; t <= k; t++) {
            dp[i][t] = INT_MAX;
        }
    }
    
    // base case: 1 mailbox
    for (int i = 0; i < n; i++) {
        dp[i][1] = cost[0][i];
    }
    
    // DP ค่อยๆเติมกล่องจดหมาย
    for (int mail = 2; mail <= k; mail++) {
        // 0..j..=i วางกล่องจดหมายล่าสุดให้บ้านหลัง j+1..=i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j][mail - 1] != INT_MAX) {
                    dp[i][mail] = MIN(dp[i][mail], dp[j][mail - 1] + cost[j + 1][i]);
                }
            }
        }
    }
    
    int result = dp[n - 1][k];
    
    // free memory
    for (int i = 0; i < n; i++) {
        free(cost[i]);
        free(dp[i]);
    }
    free(cost);
    free(dp);
    
    return result;
}