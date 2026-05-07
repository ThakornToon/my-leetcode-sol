#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSumOfLengths(int* arr, int arrSize, int target) {
    int n = arrSize;
    int* best = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) best[i] = INT_MAX;
    
    int left = 0, sum = 0;
    int minLen = INT_MAX;
    int bestSoFar = INT_MAX;
    
    for (int right = 0; right < n; right++) {
        sum += arr[right];
        
        while (sum > target) {
            sum -= arr[left];
            left++;
        }
        
        if (sum == target) {
            int curLen = right - left + 1;
            if (left > 0 && best[left - 1] != INT_MAX) {
                minLen = MIN(minLen, best[left - 1] + curLen);
            }
            bestSoFar = MIN(bestSoFar, curLen);
        }
        
        best[right] = bestSoFar;
    }
    
    free(best);
    return minLen == INT_MAX ? -1 : minLen;
}