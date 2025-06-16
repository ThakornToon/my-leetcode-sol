/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// ฟังก์ชัน Binary Search
bool biSearch(int* nums, int numsSize, int find) {
    int l = 0;
    int r = numsSize - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == find) {
            return true;
        } else if (nums[mid] < find) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int i = 0;
    while (i < nums2Size) {
        if (biSearch(nums1, nums1Size, nums2[i])) {
            res[*returnSize] = nums2[i];
            (*returnSize)++;
        }
        i++;
        while (i < nums2Size && nums2[i] == nums2[i - 1]) {
            i++;
        }
    }
    res = (int*)realloc(res, (*returnSize) * sizeof(int));
    return res;
}