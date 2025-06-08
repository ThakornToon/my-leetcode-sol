class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candi;
        for (int& num : nums) {
            if (count == 0) {
                candi = num;
            }

            if (candi == num) {
                count++;
            } else {
                count--;
            }
        }
        return candi;
    }
};