void moveZeroes(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize - 1;
    while (l < r) {
        if (nums[l] == 0) {
            for (int i = l; i < r; i++) {
                nums[i] = nums[i + 1];
            }
            nums[r] = 0;
            r--;
        }
        else {
            l++;
        }
    }
}