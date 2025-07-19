char* optimalDivision(int* nums, int numsSize) {
    char* result = (char*)malloc(1000 * sizeof(char));
    char* current = result;
    
    if (numsSize == 1) {
        current += sprintf(current, "%d", nums[0]);
    } else if (numsSize == 2) {
        current += sprintf(current, "%d/%d", nums[0], nums[1]);
    } else {
        current += sprintf(current, "%d/(", nums[0]);
        current += sprintf(current, "%d", nums[1]);
        for (int i = 2; i < numsSize; i++) {
            current += sprintf(current, "/%d", nums[i]);
        }
        current += sprintf(current, ")");
    }
    
    return result;
}