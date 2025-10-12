// Comparison function for sorting intervals
int compare(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    
    // Sort by end in ascending order
    if (interval1[1] != interval2[1]) {
        return interval1[1] - interval2[1];
    }
    // If ends are equal, sort by start in descending order
    return interval2[0] - interval1[0];
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    // Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int result = 0;
    int last = -1;
    int second_last = -1;
    
    for (int i = 0; i < intervalsSize; i++) {
        int a = intervals[i][0];
        int b = intervals[i][1];
        
        if (a > last) {
            // Case 1: No numbers from S in this interval
            result += 2;
            last = b;
            second_last = b - 1;
        } else if (a > second_last) {
            // Case 2: One number from S in this interval
            result += 1;
            second_last = last;
            last = b;
        }
        // Case 3: Already have ≥2 numbers in this interval
    }
    
    return result;
}