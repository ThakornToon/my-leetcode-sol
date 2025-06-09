int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int getMax(int* nums, int start, int end) {
    int prevRob = 0, maxRob = 0;

    for (int i = start; i <= end; ++i) {
        int temp = max(maxRob, prevRob + nums[i]);
        prevRob = maxRob;
        maxRob = temp;
    }

    return maxRob;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    return max(getMax(nums, 0, numsSize - 2), getMax(nums, 1, numsSize - 1));
}