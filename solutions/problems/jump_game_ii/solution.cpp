class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest_reachable = 0;
        int step = 0;
        int end = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            furthest_reachable = max(furthest_reachable, i + nums[i]);
            if (i == end) {
                end = furthest_reachable;
                step+=1;
            }
        }
        return step;
    }
};