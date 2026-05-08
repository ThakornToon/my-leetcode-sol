bool canArrange(int* arr, int arrSize, int k) {
    int* freq = (int*)calloc(k, sizeof(int));
    
    // นับความถี่ของ remainder
    for (int i = 0; i < arrSize; i++) {
        int rem = arr[i] % k;
        if (rem < 0) rem += k;
        freq[rem]++;
    }
    
    // remainder 0 ต้องเป็นจำนวนคู่
    if (freq[0] % 2 != 0) {
        free(freq);
        return false;
    }
    
    // ตรวจสอบคู่ (r, k-r)
    for (int r = 1; r <= k / 2; r++) {
        // ถ้า k เป็นเลขคู่ ต้องตรวจกรณี r == k-r ด้วย
        if (r == k - r) {
            if (freq[r] % 2 != 0) {
                free(freq);
                return false;
            }
        } else {
            if (freq[r] != freq[k - r]) {
                free(freq);
                return false;
            }
        }
    }
    
    free(freq);
    return true;
}