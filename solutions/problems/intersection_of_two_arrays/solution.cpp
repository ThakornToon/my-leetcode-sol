class Solution {
private:
    bool biSearch(vector<int>& nums, int find) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == find) {
                return true;
            } else if (nums[mid] < find) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0;
        while (i < nums2.size()) {
            if (biSearch(nums1, nums2[i])) {
                res.push_back(nums2[i]);
            }
            i++;
            while (i < nums2.size() && nums2[i] == nums2[i - 1]) {
                i++;
            }
        }
        return res;
    }
};