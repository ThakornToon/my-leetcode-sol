int minFlipsMonoIncr(char* s) {
    int n = strlen(s);
    if (n <= 1) return 0;
    
    // prefixOne[i] = จำนวน 1 ใน s[0..i-1]
    int* prefixOne = (int*)malloc((n + 1) * sizeof(int));
    prefixOne[0] = 0;
    
    for (int i = 0; i < n; i++) {
        prefixOne[i + 1] = prefixOne[i] + (s[i] == '1');
    }
    
    int minFlips = INT_MAX;
    
    // ลองทุกจุดแบ่ง: 0...i เป็น 0, i+1...n-1 เป็น 1
    for (int i = 0; i <= n; i++) {
        // flips ที่ต้องทำ:
        // 1. ในส่วนซ้าย (0..i-1): เปลี่ยน 1 ทั้งหมดเป็น 0
        int leftFlips = prefixOne[i] - prefixOne[0];  // 1 ในส่วนซ้าย
        
        // 2. ในส่วนขวา (i..n-1): เปลี่ยน 0 ทั้งหมดเป็น 1
        int rightFlips = (n - i) - (prefixOne[n] - prefixOne[i]);  // 0 ในส่วนขวา
        
        int totalFlips = leftFlips + rightFlips;
        if (totalFlips < minFlips) {
            minFlips = totalFlips;
        }
    }
    
    free(prefixOne);
    return minFlips;
}