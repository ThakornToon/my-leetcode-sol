class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max heap using priority_queue
        priority_queue<int> maxHeap;
        
        // Add all stones to max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        
        // Process until one or zero stones remain
        while (maxHeap.size() > 1) {
            int y = maxHeap.top();  // heaviest stone
            maxHeap.pop();
            
            int x = maxHeap.top();  // second heaviest
            maxHeap.pop();
            
            if (x != y) {
                maxHeap.push(y - x);
            }
            // If equal, both are destroyed (nothing to push)
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};