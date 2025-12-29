class Solution {
public:
    const int mod = 1e9 + 7;

    int numPrimeArrangements(int n) {
        // นับจำนวนเฉพาะจาก 1 ถึง n
        int primeCount = countPrimes(n);
        int nonPrimeCount = n - primeCount;
        
        // คำนวณ factorial ของจำนวนเฉพาะและจำนวน non-prime
        long long result = factorial(primeCount) * factorial(nonPrimeCount) % mod;
        
        return result;
    }
    
private:
    // นับจำนวนเฉพาะ <= n (Sieve of Eratosthenes)
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<bool> isPrime(n + 1, true);
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
        
        return count;
    }
    
    // คำนวณ factorial mod
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result * i) % mod;
        }
        return result;
    }
};