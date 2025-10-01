bool dfs(double* nums, int n) {
    if (n == 1) {
        return fabs(nums[0] - 24) < 1e-6;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            // สร้าง array ใหม่
            double* next_nums = (double*)malloc((n-1) * sizeof(double));
            int idx = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    next_nums[idx++] = nums[k];
                }
            }
            
            // ทดลองทุก operation
            double a = nums[i], b = nums[j];
            double operations[4];
            operations[0] = a + b;
            operations[1] = a - b;
            operations[2] = a * b;
            operations[3] = (fabs(b) > 1e-6) ? a / b : 0; // กันกรณีหารด้วย 0
            
            for (int op = 0; op < 4; op++) {
                if (op == 3 && fabs(b) < 1e-6) continue; // ถ้า b->0 จะไม่มี op นี้
                
                next_nums[n-2] = operations[op];
                if (dfs(next_nums, n-1)) {
                    free(next_nums);
                    return true;
                }
            }
            
            free(next_nums);
        }
    }
    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    double* nums = (double*)malloc(cardsSize * sizeof(double));
    for (int i = 0; i < cardsSize; i++) {
        nums[i] = (double)cards[i];
    }
    bool result = dfs(nums, cardsSize);
    free(nums);
    return result;
}