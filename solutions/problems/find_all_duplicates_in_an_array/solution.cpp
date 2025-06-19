class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i])-1; 
            if (nums[idx] < 1) { // เจอเลขนั้นครั้งที่สอง
                ans.push_back(idx + 1);
                continue;
            }
            nums[idx] *= -1; // สมมติเจอเลขที่ครั้งแรกจะ mark ค่า index 3 ใน nums เป็นค่าลบไว้
        }
        return ans;
    }
};