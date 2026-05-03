int countTriplets(int* arr, int arrSize) {
    int* prefix = (int*)malloc((arrSize + 1) * sizeof(int));
    prefix[0] = 0;
    
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int k = i + 1; k < arrSize; k++) {
            if (prefix[i] == prefix[k + 1]) {
                count += (k - i);
            }
        }
    }
    
    free(prefix);
    return count;
}