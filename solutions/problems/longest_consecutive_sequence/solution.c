
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int cnt = 1, longest = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) continue;  // Skip duplicates
        if (nums[i] == nums[i - 1] + 1) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt > longest) longest = cnt;
    }
    
    return longest;
}