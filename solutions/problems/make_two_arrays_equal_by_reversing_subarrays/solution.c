bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int count[1001] = {0};  // ตาม constraint target[i] <= 1000
    
    for (int i = 0; i < targetSize; i++) {
        count[target[i]]++;
        count[arr[i]]--;
    }
    
    for (int i = 0; i <= 1000; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}