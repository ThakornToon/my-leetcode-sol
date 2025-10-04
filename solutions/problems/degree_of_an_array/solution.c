#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int count;
    int first;
    int last;
} NumInfo;

int findShortestSubArray(int* nums, int numsSize) {    
    int min_num = INT_MAX, max_num = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        min_num = MIN(min_num, nums[i]);
        max_num = MAX(max_num, nums[i]);
    }
    
    int range = max_num - min_num + 1;
    NumInfo* info = (NumInfo*)calloc(range, sizeof(NumInfo));
    
    // Initialize first positions to -1
    for (int i = 0; i < range; i++) {
        info[i].first = -1;
    }
    
    int max_degree = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int idx = num - min_num;
        
        if (info[idx].first == -1) {
            info[idx].first = i;
        }
        info[idx].last = i;
        info[idx].count++;
        
        max_degree = MAX(max_degree, info[idx].count);
    }
    
    // Find shortest subarray length
    int min_length = INT_MAX;
    for (int i = 0; i < range; i++) {
        if (info[i].count == max_degree) {
            int length = info[i].last - info[i].first + 1;
            min_length = MIN(min_length, length);
        }
    }
    
    free(info);
    return min_length;
}