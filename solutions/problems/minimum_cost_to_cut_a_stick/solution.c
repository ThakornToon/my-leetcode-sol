#define MIN(a, b) ((a) < (b) ? (a) : (b))

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minCost(int n, int* cuts, int cutsSize) {
    // เพิ่ม 0 และ n เข้าไปด้วย
    int* allEdges = (int*)malloc((cutsSize + 2) * sizeof(int));
    for (int i = 0; i < cutsSize; i++) {
        allEdges[i + 1] = cuts[i];
    }
    allEdges[0] = 0;
    allEdges[cutsSize + 1] = n;
    
    int m = cutsSize + 2;
    qsort(allEdges, m, sizeof(int), compare);
    
    // DP table: dp[i][j] = min cost to cut between allEdges[i] and allEdges[j]
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)calloc(m, sizeof(int));
    }
    
    // ความยาวของช่วง (len = j - i) ที่คิด
    for (int len = 2; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            
            // ลองตัดที่ทุกตำแหน่ง k ระหว่าง i และ j
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + (allEdges[j] - allEdges[i]);
                dp[i][j] = MIN(dp[i][j], cost);
            }
        }
    }
    
    int result = dp[0][m - 1];
    
    // คืนหน่วยความจำ
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(allEdges);
    
    return result;
}