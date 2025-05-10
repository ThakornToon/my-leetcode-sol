bool canJump(int* nums, int numsSize) {
    int goal = numsSize - 1;

    for (int currPos = numsSize - 2; currPos >= 0; currPos--) {
        if (currPos + nums[currPos] >= goal) {
            goal = currPos;
        }
    }
    return goal == 0;
}