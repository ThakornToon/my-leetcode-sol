/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool biSearch(int* nums, int numsSize, int find, int* start) {
    int l = *start;
    int r = numsSize - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == find) {
            while (mid > *start && nums[mid] == nums[mid - 1]) {
                mid--;
            }
            *start = mid + 1;
            return true;
        } else if (nums[mid] < find) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int i = 0;
    int start = 0;
    int* res = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    
    while (i < nums2Size && start < nums1Size) {
        if (biSearch(nums1, nums1Size, nums2[i], &start)) {
            res[(*returnSize)++] = nums2[i];
        }
        i++;
    }
    res = (int*)realloc(res, (*returnSize) * sizeof(int));
    
    return res;
}