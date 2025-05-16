class Solution {
public:
    int CrossMaxSum(vector<int>& nums, int l, int r, int mid) {
        int leftSum = INT_MIN;
        int rightSum = INT_MIN;
        int currSum = 0;
        for (int i = mid; i >= l; i--) {
            currSum += nums[i];
            leftSum = max(leftSum, currSum);
        }
        currSum = 0;
        for (int i = mid + 1; i <= r; i++) {
            currSum += nums[i];
            rightSum = max(rightSum, currSum);
        }
        return leftSum + rightSum;
    }

    int divide_and_conquer(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int mid = l + (r-l) / 2;
        int left_sum = divide_and_conquer(nums, l, mid);
        int right_sum = divide_and_conquer(nums, mid+1, r);
        int cross_sum = CrossMaxSum(nums, l, r, mid);
        return max(max(left_sum, right_sum), cross_sum);
    }

    int maxSubArray(vector<int>& nums) {
        return divide_and_conquer(nums, 0, nums.size()-1);
    }
};