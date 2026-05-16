#define MOD 1000000007

int n;
int* loc;
int finishIdx;
long long** memo;

// ฟังก์ชัน DFS + Memoization
long long dfs(int pos, int fuel) {
    // ถ้าคำนวณไว้แล้ว ให้คืนค่า memo
    if (memo[pos][fuel] != -1) {
        return memo[pos][fuel];
    }
    
    long long ans = 0;
    
    // ถ้าตำแหน่งปัจจุบันคือ finish ให้ +1 (นับเส้นทางนี้)
    if (pos == finishIdx) {
        ans++;
    }
    
    // ลองไปทุกเมืองที่เป็นไปได้
    for (int next = 0; next < n; next++) {
        if (next == pos) continue; // อยู่ที่เดิมไม่ต้องไป
        
        int cost = abs(loc[pos] - loc[next]);
        if (fuel >= cost) {
            ans = (ans + dfs(next, fuel - cost)) % MOD;
        }
    }
    
    // บันทึกผลลัพธ์
    memo[pos][fuel] = ans;
    return ans;
}

int countRoutes(int* locations, int locationsSize, int start, int finish, int fuel) {
    n = locationsSize;
    loc = locations;
    finishIdx = finish;
    
    // จองหน่วยความจำสำหรับ memo [n][fuel+1] ว่าไป finish ได้กี่ทาง
    memo = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        memo[i] = (long long*)malloc((fuel + 1) * sizeof(long long));
        for (int j = 0; j <= fuel; j++) {
            memo[i][j] = -1;
        }
    }
    
    long long result = dfs(start, fuel);
    
    // ปล่อยหน่วยความจำ
    for (int i = 0; i < n; i++) {
        free(memo[i]);
    }
    free(memo);
    
    return (int)(result % MOD);
}