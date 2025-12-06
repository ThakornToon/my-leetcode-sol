class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        // sumA - x + y = sumB - y + x
        // y = x - (sumA - sumB) / 2
        int sumA = 0, sumB = 0;
        
        // คำนวณผลรวม
        for (int candy : aliceSizes) sumA += candy;
        for (int candy : bobSizes) sumB += candy;
        
        int diff = (sumA - sumB) / 2;
        
        // ใช้สำหรับการค้นหา
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        
        // หาคู่ที่ตรงกัน
        for (int x : aliceSizes) {
            int y = x - diff;
            if (bobSet.find(y) != bobSet.end()) {
                return {x, y};
            }
        }
        
        return {};
    }
};