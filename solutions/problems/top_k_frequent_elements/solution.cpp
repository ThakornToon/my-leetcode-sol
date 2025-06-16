class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map; // (num, freq)
        for (int num : nums) {
            freq_map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // เรียงตาม freq จากมากไปน้อย
        
        for (auto& [num, freq] : freq_map) {
            min_heap.push({freq, num});
            if (min_heap.size() > k) {
                min_heap.pop(); // เก็บมาเรียงถ้าเรียงแล้วมีส่วนเกินก็ตัดทิ้ง
            }
        }
        
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};