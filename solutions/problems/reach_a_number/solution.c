int reachNumber(int target) {
    target = abs(target);
    int n = 0;
    long total = 0;
    
    while (total < target) {
        n++;
        total += n;
    }
    
    while ((total - target) % 2 != 0) {
        n++;
        total += n;
    }
    
    return n;
}