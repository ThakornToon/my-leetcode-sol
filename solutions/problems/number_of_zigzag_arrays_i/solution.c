#define MOD 1000000007
int zigZagArrays(int n, int l, int r) {
    int range = r - l + 1;

    // Allocate ครั้งเดียว ไม่ malloc ในลูป
    long long* up      = (long long*)calloc(range,     sizeof(long long));
    long long* down    = (long long*)calloc(range,     sizeof(long long));
    long long* newUp   = (long long*)calloc(range,     sizeof(long long));
    long long* newDown = (long long*)calloc(range,     sizeof(long long));
    long long* prefixUp   = (long long*)malloc((range + 1) * sizeof(long long));
    long long* prefixDown = (long long*)malloc((range + 1) * sizeof(long long));

    // Base case: length 2
    for (int i = 0; i < range; i++) {
        up[i]   = i;
        down[i] = range - 1 - i;
    }

    // สร้างความยาว 3 ขึ้นไป
    for (int len = 3; len <= n; len++) {
        // ใช้ memset แทน calloc ใหม่
        memset(newUp,   0, range * sizeof(long long));
        memset(newDown, 0, range * sizeof(long long));

        // prefixUp[j] = ผลรวม up[i] โดย i < j เมื่อยาว len - 1
        // prefixDown[j] = ผลรวม down[i] โดย i < j เมื่อยาว len - 1
        prefixUp[0] = prefixDown[0] = 0;
        for (int i = 0; i < range; i++) {
            prefixUp[i + 1]   = (prefixUp[i]   + up[i])   % MOD;
            prefixDown[i + 1] = (prefixDown[i] + down[i]) % MOD;
        }

        for (int curr = 0; curr < range; curr++) {
            newUp[curr]   = prefixDown[curr];
            newDown[curr] = (prefixUp[range] - prefixUp[curr + 1] + MOD) % MOD;
        }

        // Swap pointer แทน free/malloc
        long long* tmp;
        tmp = up;   up   = newUp;   newUp   = tmp;
        tmp = down; down = newDown; newDown = tmp;
    }

    long long result = 0;
    for (int i = 0; i < range; i++)
        result = (result + up[i] + down[i]) % MOD;

    free(up); free(down); free(newUp); free(newDown);
    free(prefixUp); free(prefixDown);
    return (int)result;
}