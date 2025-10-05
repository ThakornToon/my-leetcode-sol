class Solution {
public:
    // Binary Search + Sliding Window (Optimal)
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countPairs(nums, mid);
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    // Count number of pairs with distance <= target
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        int left = 0;
        int n = nums.size();
        
        for (int right = 0; right < n; right++) {
            // Shrink window until nums[right] - nums[left] <= target
            while (nums[right] - nums[left] > target) {
                left++;
            }
            // All pairs (left, right), (left+1, right), ..., (right-1, right) satisfy
            count += (right - left);
        }
        
        return count;
    }
};