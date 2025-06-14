int minPatches(int* nums, int numsSize, int n) {
    int cnt = 0;
    long long curr = 0;
    for (int i = 0; i < numsSize && curr < n;) {
        if (nums[i] <= curr + 1) {
            curr += nums[i];
            i++;
        } else {
            cnt++;
            curr = curr * 2 + 1;
        }
    }
    while (curr < n) {
        curr = curr * 2 + 1;
        cnt++;
    }
    return cnt;
}