#define MAX_NUM 3000

// Memoization array: power[x] = power value ของ x
int powerCache[MAX_NUM + 1];

// คำนวณ power value ด้วย recursion + memoization
int getPower(int x) {
    if (x == 1) return 0;
    if (x <= MAX_NUM && powerCache[x] != -1) {
        return powerCache[x];
    }
    
    int result;
    if (x % 2 == 0) {
        result = 1 + getPower(x / 2);
    } else {
        result = 1 + getPower(3 * x + 1);
    }
    
    if (x <= MAX_NUM) {
        powerCache[x] = result;
    }
    
    return result;
}

// โครงสร้างสำหรับเก็บ (number, power)
typedef struct {
    int num;
    int power;
} NumberPower;

int compare(const void* a, const void* b) {
    NumberPower* np1 = (NumberPower*)a;
    NumberPower* np2 = (NumberPower*)b;
    
    if (np1->power != np2->power) {
        return np1->power - np2->power;
    }
    return np1->num - np2->num;
}

int getKth(int lo, int hi, int k) {
    // Initialize cache
    memset(powerCache, -1, sizeof(powerCache));
    
    int n = hi - lo + 1;
    NumberPower* arr = (NumberPower*)malloc(n * sizeof(NumberPower));
    
    for (int i = 0; i < n; i++) {
        int num = lo + i;
        arr[i].num = num;
        arr[i].power = getPower(num);
    }
    
    qsort(arr, n, sizeof(NumberPower), compare);
    
    int result = arr[k - 1].num;
    free(arr);
    return result;
}