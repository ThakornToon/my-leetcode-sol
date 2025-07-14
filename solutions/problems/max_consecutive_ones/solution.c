int max(int a, int b) {
    return (a >= b) ? a : b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int res = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            res = max(res, count);
            count = 0;
        }
    }
    return max(res, count);
}