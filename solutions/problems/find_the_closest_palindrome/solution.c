#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;

char* mirror(const char* left, int len) {
    char* res = (char*)malloc((len + 1) * sizeof(char));
    strncpy(res, left, (len+1)/2);
    for (int i = 0; i < len/2; i++) {
        res[len - 1 - i] = res[i];
    }
    res[len] = '\0';
    return res;
}

char* nearestPalindromic(char* n) {
    int len = strlen(n);
    ll num = atoll(n);
    
    if (len == 1) {
        char* res = malloc(2);
        sprintf(res, "%lld", num - 1);
        return res;
    }
    
    // Generate candidates
    ll candidates[5];
    int count = 0;
    
    // Case 1: 999...9
    candidates[count++] = (ll)pow(10, len - 1) - 1;
    
    // Case 2: 100...001
    candidates[count++] = (ll)pow(10, len) + 1;
    
    // Case 3: Mirror left half
    char prefix[20];
    strncpy(prefix, n, (len + 1)/2);
    prefix[(len + 1)/2] = '\0'; // 12698 -> 126, 1278 -> 12
    
    ll half = atoll(prefix);
    for (ll i = half - 1; i <= half + 1; i++) { // 126 -> 125, 126, 127
        char left[20];
        sprintf(left, "%lld", i);
        char* mirrored = mirror(left, len); // 12521, 12621, 12721
        candidates[count++] = atoll(mirrored);
        free(mirrored);
    }
    
    // Find closest
    ll min_diff = LLONG_MAX;
    ll result = 0;
    for (int i = 0; i < count; i++) {
        if (candidates[i] == num) continue;
        
        ll diff = llabs(candidates[i] - num);
        if (diff < min_diff || (diff == min_diff && candidates[i] < result)) {
            min_diff = diff;
            result = candidates[i];
        }
    }
    
    char* res = (char*)malloc(20 * sizeof(char));
    sprintf(res, "%lld", result);
    return res;
}