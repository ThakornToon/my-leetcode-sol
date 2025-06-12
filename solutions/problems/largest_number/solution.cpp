class Solution {
public:
    static bool compare(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);

        if (sa + sb  > sb + sa) {  //เช่นเทียบ 9 กับ 34 ว่าตัวไหนควรมาก่อนจะดูจาก 934, 349 ในรูปแบบสตริง
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        // If the largest number after sorting is '0', the result is "0"
        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};