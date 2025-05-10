void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void reverse(int* arr, int st, int end){
    while(st < end){
        swap(arr, st, end);
        st++;
        end--;
    }
}
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize-2;
    while (i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j=numsSize-1;
        while(nums[j] <= nums[i]){
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i+1, numsSize-1);
}