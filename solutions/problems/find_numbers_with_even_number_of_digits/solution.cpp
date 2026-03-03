class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        
        for (int num : nums) {
            int digitCount = (num == 0) ? 1 : (int)log10(num) + 1;
            if (digitCount % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};