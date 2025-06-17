int singleNumber(int* nums, int numsSize) {
    int one=0,multi=0;
    for(int i=0;i<numsSize;i++){
        one = (one^nums[i]) & ~multi;
        multi=(multi^nums[i]) & ~one;
    }
    return one;
}