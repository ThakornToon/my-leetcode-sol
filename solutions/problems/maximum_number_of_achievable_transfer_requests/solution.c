#define MAX_BUILDINGS 20
#define MAX_REQUESTS 16

typedef struct {
    int from;
    int to;
} Request;

int maxCount = 0;
int n, m;
Request* requests;

// ฟังก์ชันตรวจสอบว่า balance ทั้งหมดเป็น 0 หรือไม่
bool isBalanceZero(int* balance) {
    for (int i = 0; i < n; i++) {
        if (balance[i] != 0) return false;
    }
    return true;
}

// ฟังก์ชันคำนวณ maximum positive balance สำหรับ pruning
int getMaxPositive(int* balance) {
    int maxPos = 0;
    for (int i = 0; i < n; i++) {
        if (balance[i] > 0 && balance[i] > maxPos) {
            maxPos = balance[i];
        }
    }
    return maxPos;
}

// ฟังก์ชันคำนวณ maximum negative balance สำหรับ pruning
int getMaxNegative(int* balance) {
    int maxNeg = 0;
    for (int i = 0; i < n; i++) {
        if (balance[i] < 0 && -balance[i] > maxNeg) {
            maxNeg = -balance[i];
        }
    }
    return maxNeg;
}

// Branch and Bound DFS
void backtrack(int idx, int* balance, int count, int remaining) {
    // Pruning 1: ไม่สามารถดีกว่า maxCount ได้
    if (count + remaining <= maxCount) return;
    
    // Pruning 2: ถ้า balance บางตัวเป็นบวกหรือลบมากเกินไป
    int maxPos = getMaxPositive(balance);
    int maxNeg = getMaxNegative(balance);
    
    if (maxPos > remaining || maxNeg > remaining) return;
    
    // Base case: ถึงจุดสิ้นสุด
    if (idx == m) {
        if (isBalanceZero(balance)) {
            if (count > maxCount) {
                maxCount = count;
            }
        }
        return;
    }
    
    // Option 1: ไม่เลือก request นี้
    backtrack(idx + 1, balance, count, remaining - 1);
    
    // Option 2: เลือก request นี้
    int from = requests[idx].from;
    int to = requests[idx].to;
    
    // Pruning 3: ถ้าเลือกแล้วทำให้ imbalance มากขึ้นเกินไป
    int newBalance[MAX_BUILDINGS];
    memcpy(newBalance, balance, n * sizeof(int));
    newBalance[from]--;
    newBalance[to]++;
    
    int newMaxPos = getMaxPositive(newBalance);
    int newMaxNeg = getMaxNegative(newBalance);
    
    if (newMaxPos <= remaining - 1 && newMaxNeg <= remaining - 1) {
        backtrack(idx + 1, newBalance, count + 1, remaining - 1);
    }
}

// ฟังก์ชันหลัก
int maximumRequests(int n_o, int** requests_o, int requestsSize, int* requestsColSize) {
    n = n_o;
    m = requestsSize;
    
    // จองหน่วยความจำสำหรับ requests
    requests = (Request*)malloc(m * sizeof(Request));
    for (int i = 0; i < m; i++) {
        requests[i].from = requests_o[i][0];
        requests[i].to = requests_o[i][1];
    }

    // เรียงลำดับ requests เพื่อเพิ่มประสิทธิภาพ (optional)
    // เอา requests ที่ from != to มาก่อน
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (requests[i].from == requests[i].to && requests[j].from != requests[j].to) {
                Request temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
                break;
            }
        }
    }
    
    int* balance = (int*)calloc(n, sizeof(int));
    maxCount = 0;
    
    backtrack(0, balance, 0, m);
    
    free(requests);
    free(balance);
    
    return maxCount;
}