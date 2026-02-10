#define MAX_VAL 100000

int longestBalanced(int* nums, int numsSize) {
    int maxLen = 0;
    
    // Precompute parity
    int* isEven = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        isEven[i] = (nums[i] % 2 == 0);
    }
    
    // Allocate memory for seen arrays once
    int* evenSeen = (int*)calloc(MAX_VAL + 1, sizeof(int));
    int* oddSeen = (int*)calloc(MAX_VAL + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        if (numsSize - i <= maxLen) break;  // Early exit
        
        // Reset counts
        int evenCount = 0, oddCount = 0;
        
        for (int j = i; j < numsSize; j++) {
            int num = nums[j];
            
            if (isEven[j]) {
                if (evenSeen[num] <= i) {  // ใช้ i เป็น version marker
                    evenSeen[num] = i + 1;  // เก็บว่าเคยเห็นใน iteration นี้
                    evenCount++;
                }
            } else {
                if (oddSeen[num] <= i) {
                    oddSeen[num] = i + 1;
                    oddCount++;
                }
            }
            
            if (evenCount == oddCount) {
                int len = j - i + 1;
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }
    
    free(isEven);
    free(evenSeen);
    free(oddSeen);
    
    return maxLen;

}