#define max(a, b) ((a) > (b) ? (a) : (b))

long long maxSumTrionic(int* nums, int numsSize) {
    long long inc1 = nums[0];
    int haveInc1 = 0;
   
    long long dec = 0;
    int haveDec = 0;

    long long inc2 = 0;
    int haveInc2 = 0;

    long long maxSum = LLONG_MIN;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            if (haveInc1) {
                dec = inc1 + nums[i];
                haveDec = 1;
            } else if (haveDec) {
                dec += nums[i];
                haveDec = 1;
            }

            inc1 = nums[i];
            haveInc1 = 0;
            inc2 = 0;
            haveInc2 = 0;
        } else if (nums[i] > nums[i - 1]) {
            if (haveDec) {
                inc2 = dec + nums[i];
                haveInc2 = 1;
                maxSum = max(maxSum, inc2);
            } else if (haveInc2) {
                inc2 += nums[i];
                haveInc2 = 1;
                maxSum = max(maxSum, inc2);
            }

            inc1 = max(inc1 + nums[i], nums[i-1] + (long long)nums[i]);
            haveInc1 = 1;
            dec = 0;
            haveDec = 0;
        } else {
            inc1 = nums[i];
            haveInc1 = 0;
            dec = 0;
            haveDec = 0;
            inc2 = 0;
            haveInc2 = 0;
        }
    }


    return maxSum;
}