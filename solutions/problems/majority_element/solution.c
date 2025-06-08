int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int candi = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candi = nums[i];
        }

        if (candi == nums[i]) {
            count++;
        }
        else {
            count--;
            
        }
    }
    return candi;
}