#define MIN(a, b) ((a) < (b) ? (a) : (b))


int minimumDistance(int* nums, int numsSize) {
    int minDist = INT_MAX;
    
    // brute force: ตรวจสอบทุก combination
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] != nums[j]) continue;
            
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] != nums[k]) continue;
                
                // คำนวณระยะทาง
                int dist = abs(i - j) + abs(j - k) + abs(k - i);
                if (dist < minDist) {
                    minDist = dist;
                }
            }
        }
    }
    
    return (minDist == INT_MAX) ? -1 : minDist;
}