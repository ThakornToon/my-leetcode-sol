class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // เรียงลำดับจากมากไปน้อย
        sort(nums.begin(), nums.end(), greater<int>());
        
        int distinct_count = 1;
        int prev = nums[0];
        
        // หาค่าที่แตกต่างกันสามอันดับแรก
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                distinct_count++;
                prev = nums[i];
                
                if (distinct_count == 3) {
                    return nums[i];
                }
            }
        }
        
        // ถ้าไม่มีค่าสูงสุดอันดับสาม ให้คืนค่าสูงสุด
        return nums[0];
    }
};