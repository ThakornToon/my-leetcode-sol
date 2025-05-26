int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int count = 1;

    for(int i = 1; i < numsSize; i++){
        while(count < 2 && nums[i] == nums[i - 1]){
            nums[k] = nums[i];
            k++;
            count++;
        }

        if(nums[i] != nums[i - 1]){
            nums[k] = nums[i];
            count = 1;
            k++;
        }
    }

    return k;
}