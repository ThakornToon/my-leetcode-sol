int thirdMax(int* nums, int numsSize) {
    long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num == first || num == second || num == third) continue;
        
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        }
    }
    
    return (third != LLONG_MIN) ? third : first;
}