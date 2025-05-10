class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), swap_index, less_than;
    	for (swap_index = n - 2; swap_index >= 0; swap_index--) {
            if (nums[swap_index] < nums[swap_index + 1]) {
                break;
            }
        }
    	if (swap_index < 0) {
    	    reverse(nums.begin(), nums.end());
    	} 
        else {
    	    for (less_than = n - 1; less_than > swap_index; less_than--) {
                if (nums[less_than] > nums[swap_index]) {
                    break;
                }
            } 
    	    swap(nums[swap_index], nums[less_than]);
    	    reverse(nums.begin() + swap_index + 1, nums.end());
        }
    }
}; 