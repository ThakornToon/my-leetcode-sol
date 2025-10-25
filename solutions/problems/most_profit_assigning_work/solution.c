// Comparator สำหรับเรียงคู่ difficulty-profit
int compare(const void* a, const void* b) {
    int* pairA = *(int**)a;
    int* pairB = *(int**)b;
    return pairA[0] - pairB[0];
}

// Comparator สำหรับเรียง integer ปกติ
int compare_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    // สร้าง array สำหรับเก็บคู่ difficulty-profit
    int** jobs = malloc(difficultySize * sizeof(int*));
    for (int i = 0; i < difficultySize; i++) {
        jobs[i] = malloc(2 * sizeof(int));
        jobs[i][0] = difficulty[i];
        jobs[i][1] = profit[i];
    }
    
    // เรียง jobs ตาม difficulty
    qsort(jobs, difficultySize, sizeof(int*), compare);
    
    // เรียง worker
    qsort(worker, workerSize, sizeof(int), compare_int);
    
    int totalProfit = 0;
    int maxProfit = 0;
    int j = 0;
    
    for (int i = 0; i < workerSize; i++) {
        // หางานที่ worker ทำได้
        while (j < difficultySize && jobs[j][0] <= worker[i]) {
            if (jobs[j][1] > maxProfit) {
                maxProfit = jobs[j][1];
            }
            j++;
        }
        totalProfit += maxProfit;
    }
    
    // คืน memory
    for (int i = 0; i < difficultySize; i++) {
        free(jobs[i]);
    }
    free(jobs);
    
    return totalProfit;
}