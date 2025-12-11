#define MOD 1000000007

int knightDialer(int n) {    
    // จากแต่ละปุ่ม สามารถไปยังปุ่มใดได้บ้าง (แบบ knight move)
    int moves[10][3] = {
        {4, 6, -1},     // 0 → 4, 6
        {6, 8, -1},     // 1 → 6, 8
        {7, 9, -1},     // 2 → 7, 9
        {4, 8, -1},     // 3 → 4, 8
        {0, 3, 9},      // 4 → 0, 3, 9
        {-1, -1, -1},   // 5 → ไม่มี
        {0, 1, 7},      // 6 → 0, 1, 7
        {2, 6, -1},     // 7 → 2, 6
        {1, 3, -1},     // 8 → 1, 3
        {2, 4, -1}      // 9 → 2, 4
    };
    
    int moveCounts[10] = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};

    // dp[current][digit] = จำนวนวิธีมาถึง digit นี้
    int* prev = (int*)calloc(10, sizeof(int));
    int* curr = (int*)calloc(10, sizeof(int));
    
    // เริ่มต้น: ทุกปุ่มมี 1 วิธี (อยู่กับที่)
    for (int i = 0; i < 10; i++) {
        prev[i] = 1;
    }
    
    // แต่ละขั้น
    for (int step = 2; step <= n; step++) {
        for (int digit = 0; digit < 10; digit++) {
            curr[digit] = 0; // ตำแหน่งปัจจุบัน
            
            // ดูว่ามาจากปุ่มไหนได้บ้าง
            for (int k = 0; k < moveCounts[digit]; k++) {
                int from = moves[digit][k]; 
                if (from != -1) {
                    curr[digit] = (curr[digit] + prev[from]) % MOD;
                }
            }
        }
        
        // สลับ
        int* temp = prev;
        prev = curr;
        curr = temp;
    }
    
    // รวมผลลัพธ์จากทุกปุ่ม
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + prev[i]) % MOD;
    }
    
    free(prev);
    free(curr);
    
    return result;
}