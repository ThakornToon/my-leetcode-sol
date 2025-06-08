class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        if (min_val == max_val) return 0;
        int bucket_size = max(1, (max_val - min_val) / (size - 1)); //เมื่อเรียงลำดับตัวเลข n ตัวจะมีช่องว่างระหว่างตัวเลขที่อยู่ติดกันทั้งหมด n-1 ช่อง (average gap)
        int bucket_num = (max_val - min_val) / bucket_size + 1;
        vector<int> bucketLargest(bucket_num, INT_MIN);
        vector<int> bucketSmallest(bucket_num, INT_MAX);
        for (int i = 0; i < size; i++){
            int index = (nums[i] - min_val) / bucket_size;
            bucketLargest[index] = max(bucketLargest[index], nums[i]);
            bucketSmallest[index] = min(bucketSmallest[index], nums[i]);
        }

        int max_gap = 0;
        int i = 0;
        int j = 1;
        while (j < bucket_num) {
            if (bucketLargest[j] == INT_MIN){
                j++;
            }
            else if (bucketLargest[i] == INT_MIN){
                i++;
            }
            else{
                max_gap = max(max_gap, bucketSmallest[j] - bucketLargest[i]);
                i++;
                j++;
            }
        }
        return max_gap;
    }
};