int distributeCandies(int* candyType, int candyTypeSize) {
    const int OFFSET = 100000;
    const int SIZE = 200001;
    
    int* seen = (int*)calloc(SIZE, sizeof(int));
    int uniqueCount = 0;
    
    // Count unique candy types
    for (int i = 0; i < candyTypeSize; i++) {
        int index = candyType[i] + OFFSET;
        if (!seen[index]) {
            seen[index]++;
            uniqueCount++;
        }
    }
    
    free(seen);
    
    int maxKeep = candyTypeSize / 2;
    return (uniqueCount < maxKeep) ? uniqueCount : maxKeep;
}