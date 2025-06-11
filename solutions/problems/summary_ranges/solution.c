/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** res = (char**)malloc(20 * sizeof(char*));
    int start, end;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        start = nums[i];
        while (i + 1 < numsSize && nums[i] + 1 == nums[i+1]) {
            i++;
        }
        end = nums[i];
        res[*returnSize] = calloc(25, sizeof(char));
        if (start == end) {
            snprintf(res[*returnSize], 25, "%d", start);
        } else {
            snprintf(res[*returnSize], 25, "%d->%d", start, end);
        }
        (*returnSize)++;
    }
    return res;
}