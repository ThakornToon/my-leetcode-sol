/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    /*
        ans∣(ans+1)=x.

        Observing ans+1, it is evident that this operation flips the first 0 bit 
        from the least significant bit toward the most significant bit to 1, 
        and sets all lower bits that were previously 1 to 0. 
        ans∣(ans+1) effectively changes the first 0 bit in ans, 
        scanning from the least significant bit upward, to 1.

        This implies that for any 1 bit that appears before the first 0 bit 
        (from least significant to most significant) in the binary representation of x, 
        changing that 1 to 0 will produce a valid ans such that ans∣(ans+1)=x.

        Since the problem asks for the smallest ans, 
        we only need to locate the position pos of the first 0 bit in x 
        and set the 1 bit at position pos−1 to 0.

        The implementation works as follows. We use d to track the current bit position. 
        While the current bit in x is 1, we update res to x−d, which flips that bit to 0. 
        We then shift d left by one bit and continue. When a 0 bit is encountered, no smaller valid ans can be formed, and the loop terminates.
    */

    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int res = -1;
        int d = 1;
        while ((x & d) != 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
}