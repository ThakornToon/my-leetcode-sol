#define ALPHABET_SIZE 26

int numSplits(char* s) {
    int n = strlen(s);
    
    // prefixCount[i] = จำนวนตัวอักษรที่แตกต่างใน s[0..i]
    int* prefixDistinct = (int*)malloc(n * sizeof(int));
    // suffixDistinct[i] = จำนวนตัวอักษรที่แตกต่างใน s[i..n-1]
    int* suffixDistinct = (int*)malloc(n * sizeof(int));
    
    // ใช้ array สำหรับนับตัวอักษร
    int seen[ALPHABET_SIZE] = {0};
    int distinct = 0;
    
    // คำนวณ prefixDistinct
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (seen[idx] == 0) {
            seen[idx] = 1;
            distinct++;
        }
        prefixDistinct[i] = distinct;
    }
    
    // reset array
    memset(seen, 0, sizeof(seen));
    distinct = 0;
    
    // คำนวณ suffixDistinct
    for (int i = n - 1; i >= 0; i--) {
        int idx = s[i] - 'a';
        if (seen[idx] == 0) {
            seen[idx] = 1;
            distinct++;
        }
        suffixDistinct[i] = distinct;
    }
    
    // นับจำนวน split ที่ดี
    int count = 0;
    // split ระหว่าง i กับ i+1 (prefix = [0..i], suffix = [i+1..n-1])
    for (int i = 0; i < n - 1; i++) {
        if (prefixDistinct[i] == suffixDistinct[i + 1]) {
            count++;
        }
    }
    
    free(prefixDistinct);
    free(suffixDistinct);
    
    return count;
}