class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        if (n % 2 != 0) return false;
        
        // เรียงตามค่าสัมบูรณ์
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        
        unordered_map<int, int> count;
        
        // นับความถี่
        for (int num : arr) {
            count[num]++;
        }
        
        // ตรวจสอบทีละตัวตามลำดับที่เรียงแล้ว
        for (int num : arr) {
            if (count[num] == 0) continue;
            
            int target = num * 2;
            
            if (count[target] == 0) {
                return false;
            }
            
            // ลดจำนวน
            count[num]--;
            count[target]--;
        }
        
        return true;
    }
};