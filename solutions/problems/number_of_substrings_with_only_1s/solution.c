#define MOD 1000000007
int numSub(char* s) {
    long long result = 0;
    long long count = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            count++;
            result = (result + count) % MOD;
        } else {
            count = 0;
        }
    }
    
    return (int)result;
}