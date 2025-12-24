/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* sampleStats(int* count, int countSize, int* returnSize) {
    double* result = (double*)malloc(5 * sizeof(double));
    *returnSize = 5;
    
    int total = 0;
    long long sum = 0;
    int min = -1, max = 0;
    int mode = 0;
    int max_count = 0;
    
    // 1. หา Min, Max, Mode, Total, Sum
    for (int i = 0; i < countSize; i++) {
        if (count[i] > 0) {
            if (min == -1) min = i;
            max = i;
            
            total += count[i];
            sum += (long long)i * count[i];
            
            if (count[i] > max_count) {
                max_count = count[i];
                mode = i;
            }
        }
    }
    
    // 2. Mean
    double mean = (double)sum / total;
    
    // 3. Median
    double median = 0.0;
    int half = total / 2;
    
    if (total % 2 == 1) { // total คี่
        int cnt = 0;
        for (int i = 0; i < countSize; i++) {
            cnt += count[i];
            if (cnt > half) {
                median = i;
                break;
            }
        }
    } else { // total คู่
        int cnt = 0;
        int first = -1, second = -1;
        for (int i = 0; i < countSize; i++) {            
            if (cnt < half && cnt + count[i] >= half) {
                first = i;
            }
            if (cnt < half + 1 && cnt + count[i] >= half + 1) {
                second = i;
                break;
            }
            cnt += count[i];
        }
        median = (first + second) / 2.0;
    }
    
    result[0] = (double)min;
    result[1] = (double)max;
    result[2] = mean;
    result[3] = median;
    result[4] = (double)mode;
    
    return result;
}