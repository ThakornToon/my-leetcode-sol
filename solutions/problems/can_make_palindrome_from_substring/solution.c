/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);
    
    // สร้าง prefix parity array ว่าความยาวนั้นมีตัวอักษรใดบ้างที่มีคี่ตัว
    int* prefix = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        int bit = 1 << (s[i] - 'a');
        prefix[i + 1] = prefix[i] ^ bit; // XOR คู่->คี่->คู่ 
        /*
        0 XOR 0 = 0
        0 XOR 1 = 1
        1 XOR 0 = 1
        1 XOR 1 = 0 
        */
    }
    
    bool* result = (bool*)malloc(queriesSize * sizeof(bool));
    
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        int k = queries[i][2];
        
        // หา parity ของ substring
        // คู่ ^ คี่ = 1, คี่ ^ คี่ = 0, คู่ ^ คู่ = 0
        int parity = prefix[right + 1] ^ prefix[left];
        
        // นับจำนวน bit ที่เป็น 1 (ตัวอักษรคี่ตัว)
        int oddCount = 0;
        int temp = parity;
        while (temp > 0) {
            oddCount += temp & 1;
            temp >>= 1;
        }
        
        // คำนวณจำนวนการเปลี่ยนที่ต้องการ
        int neededChanges = oddCount / 2;
        
        result[i] = (neededChanges <= k);
    }
    
    free(prefix);
    *returnSize = queriesSize;
    return result;
}