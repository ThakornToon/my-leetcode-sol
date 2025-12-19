class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int remainder = 0;
        
        for (int num : nums) {
            remainder = (remainder * 2 + num) % 5;
            answer.push_back(remainder == 0);
        }
        
        return answer;
    }
};