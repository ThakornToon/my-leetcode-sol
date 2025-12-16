class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        // ฟังก์ชันพลิก
        auto flip = [&](int k) {
            result.push_back(k);
            reverse(arr.begin(), arr.begin() + k);
        };
        
        // เรียงจากใหญ่ไปเล็ก
        for (int target = n; target > 0; target--) {
            // หาตำแหน่งของ target
            int pos = find(arr.begin(), arr.begin() + target, target) - arr.begin();
            
            // ถ้าอยู่ในตำแหน่งที่ถูกต้องแล้ว ข้าม
            if (pos == target - 1) {
                continue;
            }
            
            // พลิกให้ไปอยู่ตำแหน่งแรก (ถ้ายังไม่อยู่ที่ตำแหน่ง 0)
            if (pos != 0) {
                flip(pos + 1);
            }
            
            // พลิกให้ไปอยู่ตำแหน่งที่ถูกต้อง
            flip(target);
        }
        
        return result;
    }
};