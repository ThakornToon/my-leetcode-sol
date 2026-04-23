int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;  // เรียงจากมากไปน้อย
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    // เรียงจากมากไปน้อย
    qsort(satisfaction, satisfactionSize, sizeof(int), compare);
    
    int prefixSum = 0;
    int total = 0;
    int result = 0;
    
    for (int i = 0; i < satisfactionSize; i++) {
        prefixSum += satisfaction[i];
        total += prefixSum;
        
        if (total > result) {
            result = total;
        }
    }
    
    return result;
}