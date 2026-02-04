class Solution {
    public long maxSumTrionic(int[] nums) {
        long inc1 = nums[0];
        int haveInc1 = 0;
        long dec = 0;
        int haveDec = 0;
        long inc2 = 0;
        int haveInc2 = 0;
        long maxSum = Long.MIN_VALUE;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                if (haveInc1 != 0) {
                    dec = inc1 + nums[i];
                    haveDec = 1;
                } else if (haveDec != 0) {
                    dec += nums[i];
                    haveDec = 1;
                }

                inc1 = nums[i];
                haveInc1 = 0;
                inc2 = 0;
                haveInc2 = 0;
            } else if (nums[i] > nums[i - 1]) {
                if (haveDec != 0) {
                    inc2 = dec + nums[i];
                    haveInc2 = 1;
                    maxSum = Math.max(maxSum, inc2);
                } else if (haveInc2 != 0) {
                    inc2 += nums[i];
                    haveInc2 = 1;
                    maxSum = Math.max(maxSum, inc2);
                }

                long option1 = inc1 + nums[i];
                long option2 = (long)nums[i - 1] + nums[i];
                inc1 = Math.max(option1, option2);
                haveInc1 = 1;
                dec = 0;
                haveDec = 0;
            } else {
                inc1 = nums[i];
                dec = 0;
                haveDec = 0;
                inc2 = 0;
                haveInc2 = 0;
            }
        }

        return maxSum;
    }
}