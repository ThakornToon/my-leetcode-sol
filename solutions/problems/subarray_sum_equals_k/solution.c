typedef struct {
    int key;
    int value;
} HashEntry;

int subarraySum(int* nums, int numsSize, int k) {
    HashEntry* map = (HashEntry*)malloc(numsSize * sizeof(HashEntry) * 2);
    int mapSize = 0;
    int count = 0;
    int prefixSum = 0;
    
    // เพิ่ม 0 เพื่อนับกรณีที่ prefixSum เท่ากับ k
    map[mapSize].key = 0;
    map[mapSize].value = 1;
    mapSize++;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        
        // ตรวจสอบว่า (prefixSum - k) มีใน map หรือไม่
        
        int found = 0;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].key == (prefixSum - k)) {
                count += map[j].value;
            }
            if (map[j].key == prefixSum) {
                map[j].value++;
                found = 1;
            }
        }
        
        if (!found) {
            map[mapSize].key = prefixSum;
            map[mapSize].value = 1;
            mapSize++;
        }
    }
    
    free(map);
    return count;
}