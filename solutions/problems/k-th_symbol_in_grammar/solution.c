int kthGrammar(int n, int k) {
    // Base case
    if (n == 1) {
        return 0;
    }
    
    // Find parent position
    int parent = kthGrammar(n - 1, (k + 1) / 2);
    
    // Determine current value based on parent and position
    if (parent == 0) {
        return (k % 2 == 1) ? 0 : 1;
    } else {
        return (k % 2 == 1) ? 1 : 0;
    }
}