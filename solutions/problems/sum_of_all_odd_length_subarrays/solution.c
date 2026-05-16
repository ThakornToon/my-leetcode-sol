int sumOddLengthSubarrays(int* arr, int arrSize) {
    // สร้าง prefix sum array
    int* prefix = (int*)malloc((arrSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    
    int total = 0;
    // ลองทุกความยาวคี่
    for (int len = 1; len <= arrSize; len += 2) {
        for (int start = 0; start + len <= arrSize; start++) {
            int sum = prefix[start + len] - prefix[start];
            total += sum;
        }
    }
    
    free(prefix);
    return total;
}