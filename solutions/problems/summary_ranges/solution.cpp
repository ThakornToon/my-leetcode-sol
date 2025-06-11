class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MIN);
        vector<string> ans;
        string temp = "";
        bool flag = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (flag) {
                temp += to_string(nums[i]);
                if (nums[i + 1] != (long long)nums[i] + 1) {
                    ans.push_back(temp);
                    temp = "";
                    continue;
                }
            }
            flag = false;
            if (nums[i + 1] == (long long)nums[i] + 1) {
                continue;
            } else {
                temp += "->" + to_string(nums[i]);
                ans.push_back(temp);
                flag = true;
                temp = "";
            }
        }
        return ans;
    }
};