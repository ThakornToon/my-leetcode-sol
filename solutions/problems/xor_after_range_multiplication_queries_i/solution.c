#define MOD 1000000007


int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    // สร้าง array สำหรับเก็บค่า (copy จาก nums)
    int* arr = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }
    
    // ทำตาม query แต่ละตัว
    for (int q = 0; q < queriesSize; q++) {
        int li = queries[q][0];
        int ri = queries[q][1];
        int ki = queries[q][2];
        int vi = queries[q][3];
        
        // วนลูปจาก li ถึง ri โดยเพิ่มทีละ ki
        for (int idx = li; idx <= ri; idx += ki) {
            arr[idx] = (int)(((long long)arr[idx] * vi) % MOD);
        }
    }
    
    // คำนวณ XOR ของทุก element
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= arr[i];
    }
    
    free(arr);
    return result;
}