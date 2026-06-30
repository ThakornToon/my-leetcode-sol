class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // ใส่ k ตัวแรก
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }
        
        // สำหรับตัวที่เหลือ
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        
        return minHeap.top();
    }
};