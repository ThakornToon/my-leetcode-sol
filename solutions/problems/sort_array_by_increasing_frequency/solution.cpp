class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // นับความถี่
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // เรียงลำดับ nums
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b]; // frequency น้อยไปมาก
            }
            return a > b; // value มากไปน้อย
        });
        
        return nums;
    }
};