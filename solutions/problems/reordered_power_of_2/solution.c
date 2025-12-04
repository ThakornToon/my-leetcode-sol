// ฟังก์ชันหาจำนวนครั้งของแต่ละเลข 0-9
void getCount(int n, int* count) {    
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }
}

// ตรวจสอบว่า count 2 อันเท่ากันไหม
bool countEqual(int* count1, int* count2) {
    for (int i = 0; i < 10; i++) {
        if (count1[i] != count2[i]) return false;
    }
    return true;
}

bool reorderedPowerOf2(int n) {
    // หา signature ของ n
    int nCount[10] = {0};
    getCount(n, nCount);
    
    // ตรวจสอบทุก power of 2 ที่อยู่ใน range
    for (int p = 1; p <= 1e9; p <<= 1) {  // p = 1, 2, 4, 8, 16, ...
        int pCount[10] = {0};
        getCount(p, pCount);
        
        if (countEqual(nCount, pCount)) {
            return true;
        }
    }
    
    return false;
}