int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int numFriendRequests(int* ages, int agesSize) {
    // Sort ages first
    qsort(ages, agesSize, sizeof(int), compare);
    
    int requests = 0;
    
    for (int i = 0; i < agesSize; i++) {
        int x = ages[i];
        
        // Age must be at least 15 to send requests
        if (x < 15) continue;
        
        int lower_bound = x / 2 + 7;
        
        // Find first index where age > lower_bound
        int left = 0, right = agesSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ages[mid] <= lower_bound) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int start = left;
        
        // Find last index where age <= x
        left = 0, right = agesSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ages[mid] <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int end = right;
        
        // Count valid requests
        if (end >= start) {
            requests += end - start + 1;
            // Subtract self
            if (i >= start && i <= end) {
                requests--;
            }
        }
    }
    
    return requests;
}