int minNumberOperations(int* target, int targetSize) {
    int result = target[0];
    
    for (int i = 1; i < targetSize; i++) {
        result += (target[i] > target[i - 1]) ? target[i] - target[i - 1] : 0;
    }
    
    return result;
}