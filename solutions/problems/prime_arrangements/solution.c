#define MOD 1000000007

int countPrimes(int n) {    
    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    
    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // นับจำนวนเฉพาะ
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) count++;
    }
    
    free(isPrime);
    return count;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int numPrimeArrangements(int n) {
    int primeCount = countPrimes(n);
    int nonPrimeCount = n - primeCount;
    
    long long primeFact = factorial(primeCount);
    long long nonPrimeFact = factorial(nonPrimeCount);
    
    long long result = (primeFact * nonPrimeFact) % MOD;
    
    return (int)result;
}