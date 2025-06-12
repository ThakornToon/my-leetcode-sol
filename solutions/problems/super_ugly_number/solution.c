int min(int a, int b) {
    return (a <= b) ? a : b;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* idx = (int*)calloc(primesSize, sizeof(int));
    int* ugly = (int*)malloc(n * sizeof(int));
    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
        ugly[i] = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            if (ugly[idx[j]] < INT_MAX / primes[j]) {  // ตรวจสอบไม่ให้เกิด overflow
                ugly[i] = min(ugly[i], ugly[idx[j]] * primes[j]);
            }
        }
        for (int j = 0; j < primesSize; j++) {
            if (ugly[idx[j]] < INT_MAX / primes[j] && ugly[i] == ugly[idx[j]] * primes[j]) {
                idx[j]++;
            }
        }
    }
    int ans = (int)ugly[n - 1];
    free(idx);
    free(ugly);
    return ans;
}