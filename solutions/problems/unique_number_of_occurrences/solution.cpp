class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // 2. ตรวจสอบว่าความถี่ไม่ซ้ำกัน
        unordered_set<int> freqSet;
        for (auto& [num, count] : freq) {
            if (freqSet.count(count)) {
                return false;  // พบค่าความถี่ซ้ำ
            }
            freqSet.insert(count);
        }
        
        return true;
    }
};