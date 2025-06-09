int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int rob(int* nums, int numsSize) {
    int prevRob = 0, maxRob = 0;

    for (int i = 0; i < numsSize; i++) {
        int temp = max(maxRob, prevRob + nums[i]);
        prevRob = maxRob;
        maxRob = temp;
    }

    return maxRob;
}