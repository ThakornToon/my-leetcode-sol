int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), compare);
    qsort(heaters, heatersSize, sizeof(int), compare);
    
    int radius = 0;
    int i = 0;
    
    for (int j = 0; j < housesSize; j++) {
        while (i < heatersSize - 1 && 
               abs(heaters[i+1] - houses[j]) <= abs(heaters[i] - houses[j])) {
            i++;
        }
        int current = abs(heaters[i] - houses[j]);
        if (current > radius) {
            radius = current;
        }
    }
    
    return radius;
}