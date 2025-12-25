class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // นับความถี่ของแต่ละตัวเลขใน arr1
        unordered_map<int, int> freq;
        for (int num : arr1) {
            freq[num]++;
        }
        
        vector<int> result;
        
        // ใส่ตัวเลขตามลำดับใน arr2
        for (int num : arr2) {
            if (freq.count(num)) {
                for (int i = 0; i < freq[num]; i++) {
                    result.push_back(num);
                }
                freq.erase(num); // ลบออกหลังจากใส่แล้ว
            }
        }
        
        // ใส่ตัวเลขที่เหลือ (ที่ไม่ใช่ใน arr2) เรียงลำดับ
        vector<int> remaining;
        for (auto& [num, count] : freq) {
            for (int i = 0; i < count; i++) {
                remaining.push_back(num);
            }
        }
        sort(remaining.begin(), remaining.end());
        
        // รวมผลลัพธ์
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    }
};