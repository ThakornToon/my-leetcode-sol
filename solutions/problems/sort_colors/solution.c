void sortColors(int* nums, int numsSize) {
    bool stop = false;
    while (!stop) {
        stop = true;
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                stop = false;
            }
        }
        if (stop) {
            break;
        }
    }
}