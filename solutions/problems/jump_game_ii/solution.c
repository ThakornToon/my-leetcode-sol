int jump(int* nums, int numsSize) {
    int furthest_reachable = 0;
    int step = 0;
    int end = 0;

    for (int i = 0; i < numsSize-1; i++) {
        furthest_reachable = (furthest_reachable > i + nums[i]) ? furthest_reachable : i + nums[i];
        if (i == end) {
            end = furthest_reachable;
            step+=1;
        }
    }
    return step;
}