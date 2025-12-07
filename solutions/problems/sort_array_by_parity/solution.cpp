class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even_ptr = 0;  // ตำแหน่งที่จะวางเลขคู่
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                // สลับเลขคู่กับตำแหน่ง even_ptr
                swap(nums[i], nums[even_ptr]);
                even_ptr++;
            }
        }
        
        return nums;
    }
};