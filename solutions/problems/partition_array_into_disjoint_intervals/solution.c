int partitionDisjoint(int* nums, int numsSize) {
    int partition = 0;
    int maxLeft = nums[0];
    int maxSoFar = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < maxLeft) {
            // พบ element ที่ทำให้ partition ต้องย้ายไปทางขวา
            partition = i;
            maxLeft = maxSoFar;
        } else if (nums[i] > maxSoFar) {
            maxSoFar = nums[i];
        }
    }
    
    return partition + 1; // ความยาวของ left partition
}