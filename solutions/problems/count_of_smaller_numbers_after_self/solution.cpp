class Solution {
private: 
    void mergeSort(vector<pair<int, int>>& nums_with_index, vector<int>& counts, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums_with_index, counts, left, mid);
        mergeSort(nums_with_index, counts, mid + 1, right);

        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int right_count = 0;
        while (i <= mid && j <= right) {
            if (nums_with_index[i].first > nums_with_index[j].first) {
                right_count++;
                temp[k++] = nums_with_index[j++];
            } else {
                counts[nums_with_index[i].second] += right_count;
                temp[k++] = nums_with_index[i++];
            }
        }
        
        while (i <= mid) {
            counts[nums_with_index[i].second] += right_count;
            temp[k++] = nums_with_index[i++];
        }
        
        while (j <= right) {
            temp[k++] = nums_with_index[j++];
        }
        
        for (int idx = 0; idx < temp.size(); idx++) {
            nums_with_index[left + idx] = temp[idx];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); i++) {
            nums_with_index.emplace_back(nums[i], i);
        }
        
        vector<int> counts(nums.size(), 0);
        mergeSort(nums_with_index, counts, 0, nums.size() - 1);
        return counts;
    }
};