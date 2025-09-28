int compare(const void* a, const void* b) {
    int* pair1 = *(int**)a;
    int* pair2 = *(int**)b;
    return pair1[1] - pair2[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    // เรียงลำดับตาม b (สิ้นสุด)
    qsort(pairs, pairsSize, sizeof(int*), compare);
    
    int count = 1;
    int current_end = pairs[0][1];
    
    for (int i = 1; i < pairsSize; i++) {
        if (pairs[i][0] > current_end) {
            count++;
            current_end = pairs[i][1];
        }
    }
    
    return count;
}