/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    while (left < right) {
        int total = numbers[left] + numbers[right];

        if (total == target) {
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        } else if (total > target) {
            right--;
        } else {
            left++;
        }
    }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
}