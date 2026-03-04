int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int findBestValue(int* arr, int arrSize, int target) {
    // sort array
    qsort(arr, arrSize, sizeof(int), compare);
    
    // คำนวณ prefix sum
    int* prefix = (int*)malloc((arrSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    
    int left = 0;
    int right = arr[arrSize - 1];
    int bestValue = 0;
    int minDiff = INT_MAX;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // ใช้ binary search หาตำแหน่งแรกที่ arr[i] > mid
        int pos = 0;
        int low = 0, high = arrSize - 1;
        while (low <= high) {
            int midPos = low + (high - low) / 2;
            if (arr[midPos] <= mid) {
                pos = midPos + 1;  // ยัง <= อยู่ เลื่อน pos ไป
                low = midPos + 1;
            } else {
                high = midPos - 1;
            }
        }
        
        // คำนวณ sum = sum of elements <= mid + (n-pos) * mid
        int sum = prefix[pos] + (arrSize - pos) * mid;
        int diff = abs(sum - target);
        
        if (diff < minDiff || (diff == minDiff && mid < bestValue)) {
            minDiff = diff;
            bestValue = mid;
        }
        
        if (sum < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    free(prefix);
    return bestValue;
}