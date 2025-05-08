class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int c = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]>=target){
                return c;
            }
            c+=1;
        }
        return c;
    }
};