class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq; // max-heap
        int minVal = INT_MAX;
        
        // แปลงเลขคี่ทั้งหมดให้เป็นเลขคู่ (multiply by 2)
        for (int num : nums) {
            if (num % 2 == 1) {
                num *= 2;
            }
            pq.push(num);
            minVal = min(minVal, num);
        }
        
        int minDeviation = pq.top() - minVal;
        
        while (pq.top() % 2 == 0) {
            int maxVal = pq.top();
            pq.pop();
            
            // หาร 2
            maxVal /= 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
            
            minDeviation = min(minDeviation, pq.top() - minVal);
        }
        
        return minDeviation;
    }
};