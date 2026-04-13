#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int getMinDistance(int* nums, int numsSize, int target, int start) {
    int minDist = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            int dist = ABS(i - start);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    
    return minDist;
}