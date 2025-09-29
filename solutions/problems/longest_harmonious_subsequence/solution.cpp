class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // นับความถี่ของแต่ละตัวเลข
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_length = 0;
        
        // ตรวจสอบคู่ตัวเลขที่ต่างกัน 1
        for (auto& [num, count] : freq) {
            if (freq.find(num + 1) != freq.end()) {
                max_length = max(max_length, count + freq[num + 1]);
            }
        }
        
        return max_length;
    }
};