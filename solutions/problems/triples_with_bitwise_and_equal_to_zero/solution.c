#define MAX_VAL 65536  // 2^16 -> 1000000000000000

int countTriplets(int* nums, int numsSize) {
    // Frequency of pairwise AND results
    int* freq = (int*)calloc(MAX_VAL, sizeof(int));
    
    // Step 1: Count frequency of nums[i] & nums[j]
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            int andVal = nums[i] & nums[j];
            freq[andVal]++;
        }
    }
    
    // Step 2: Count triples where (nums[i] & nums[j] & nums[k]) == 0
    int count = 0;
    for (int k = 0; k < numsSize; k++) {
        int num = nums[k];
        
        // We need to find all masks where (mask & num) == 0
        // Instead of iterating all masks, use complement approach
        int complement = (~num) & (MAX_VAL - 1);
        
        // Iterate all submasks of complement
        int submask = complement;
        do {
            // submask - 1: ลดค่าลง 1 → เปลี่ยน bit ล่างสุดจาก 1 เป็น 0 และ set bit ทางขวาเป็น 1
            // & complement: เอาเฉพาะ bit ที่อยู่ใน complement
            // ผลลัพธ์: ได้ submask ที่มีค่าลดลง (ใน lexical order)
            count += freq[submask];
            submask = (submask - 1) & complement;
        } while (submask != complement);
    }
    
    free(freq);
    return count;
}