class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.reserve(nums.size() + 1);
        prefix.push_back(0);
        
        for (int num : nums) {
            prefix.push_back(prefix.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */