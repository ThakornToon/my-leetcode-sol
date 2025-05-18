char* getPermutation(int n, int k) {
    char* res = (char*)calloc(n + 1, sizeof(char));
    char* digits = (char*)malloc(n + 1);
    int* factorials = (int*)malloc((n + 1) * sizeof(int));
    factorials[0] = 1;

    for (int i = 1; i <= n; i++) {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i < n; i++) {
        digits[i] = i + '1';
    }
    digits[n] = '\0';
    k -= 1; // Start permutation count k with a zero-based index

    for (int i = 0; i < n; i++) {
        int blockSize = factorials[n - 1 - i];
        int index = k / blockSize;
        res[i] = digits[index];

        for (int j = index; j < n - 1 - i; j++) {
            digits[j] = digits[j + 1];
        }
        k %= blockSize;
    }

    res[n] = '\0';

    free(digits);
    free(factorials);
    return res;
}