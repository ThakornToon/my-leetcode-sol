int shipWithinDays(int* weights, int weightsSize, int days) {
    int minCapacity = 0;
    int maxCapacity = 0;
    
    // หาค่าสูงสุดและผลรวมทั้งหมด
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > minCapacity) {
            minCapacity = weights[i];
        }
        maxCapacity += weights[i];
    }
    
    // Binary Search
    while (minCapacity < maxCapacity) {
        int mid = minCapacity + (maxCapacity - minCapacity) / 2;
        int sum = 0;
        int requiredDays = 1;
        
        for (int i = 0; i < weightsSize; i++) {
            if (sum + weights[i] > mid) {
                requiredDays++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        
        if (requiredDays <= days) {
            maxCapacity = mid;
        } else {
            minCapacity = mid + 1;
        }
    }
    
    return maxCapacity;
}