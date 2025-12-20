int compare(const void* a, const void* b) {
    int* costA = *(int**)a;
    int* costB = *(int**)b;
    
    // Compare (aCost - bCost)
    int diffA = costA[0] - costA[1];
    int diffB = costB[0] - costB[1];
    
    return diffA - diffB;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    // Sort based on (aCost - bCost)
    qsort(costs, costsSize, sizeof(int*), compare);
    
    int total = 0;
    int n = costsSize / 2;
    
    // First n people go to city A, last n people go to city B
    for (int i = 0; i < n; i++) {
        total += costs[i][0];  // City A
    }
    for (int i = n; i < 2 * n; i++) {
        total += costs[i][1];  // City B
    }
    
    return total;
}