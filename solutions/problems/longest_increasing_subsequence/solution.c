int binarySearch(int* res,int size,int target){
    int l = 0;
    int r = size - 1;
    while (l < r){
        int m = (l + r) / 2;
        if (res[m] == target){
            return m;
        } else if (res[m] < target){
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}
int lengthOfLIS(int* nums, int numsSize) {
    int size = 1;
    int* res = (int*)malloc(numsSize*sizeof(int));
    res[0] = nums[0];
    for(int i = 1; i < numsSize; i++) {
        if (res[size - 1] < nums[i]) {
            res[size++] = nums[i];
        } else{
            int index = binarySearch(res, size, nums[i]);
            res[index] = nums[i];
        }
    }
    return size;
}