int max (int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int min (int a, int b) {
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }
}

int maxProduct(int* nums, int numsSize) {
    int currmax = 1;
    int currmin = 1;
    int res = nums[0];
    for (int i = 0; i < numsSize; i++) {
        int temp = currmax * nums[i];
        currmax = max(nums[i], max(temp, currmin * nums[i]));
        currmin = min(nums[i], min(temp, currmin * nums[i]));
        res = max(currmax, res);
    }
    return res;
}