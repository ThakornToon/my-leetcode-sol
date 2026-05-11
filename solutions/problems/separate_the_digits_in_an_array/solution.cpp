class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        
        for (int num : nums) {
            string numStr = to_string(num);
            for (char c : numStr) {
                result.push_back(c - '0');
            }
        }
        
        return result;
    }
};