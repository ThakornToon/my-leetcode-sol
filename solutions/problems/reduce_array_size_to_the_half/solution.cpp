class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int target = n / 2;
        
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        
        priority_queue<int> pq;
        for (auto& p : freqMap) {
            pq.push(p.second);
        }
        
        int sum = 0;
        int result = 0;
        
        while (!pq.empty() && sum < target) {
            sum += pq.top();
            pq.pop();
            result++;
        }
        
        return result;
    }
};