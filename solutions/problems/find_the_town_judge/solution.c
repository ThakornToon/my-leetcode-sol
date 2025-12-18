int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    // สร้าง array สำหรับนับ trust ที่ให้และได้รับ
    int* trustGiven = (int*)calloc(n + 1, sizeof(int));   // out-degree
    int* trustReceived = (int*)calloc(n + 1, sizeof(int)); // in-degree
    
    // นับ trust relationships
    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];  // คนที่ให้ trust
        int b = trust[i][1];  // คนที่ได้รับ trust
        
        trustGiven[a]++;
        trustReceived[b]++;
    }
    
    // หาคนที่เป็น town judge
    for (int i = 1; i <= n; i++) {
        if (trustGiven[i] == 0 && trustReceived[i] == n - 1) {
            free(trustGiven);
            free(trustReceived);
            return i;
        }
    }
    
    free(trustGiven);
    free(trustReceived);
    return -1;
}