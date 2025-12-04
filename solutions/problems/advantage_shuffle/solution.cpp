class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Sort nums1
        sort(nums1.begin(), nums1.end());
        
        // สร้าง max heap ของ nums2 (เก็บค่าและ index) เรียง value มากไปน้อย
        priority_queue<pair<int, int>> maxHeap;  // (value, index)
        for (int i = 0; i < n; i++) {
            maxHeap.push({nums2[i], i});
        }
        
        vector<int> result(n);
        int left = 0, right = n - 1;
        
        while (!maxHeap.empty()) {
            auto [value, idx] = maxHeap.top();
            maxHeap.pop();
            
            if (nums1[right] > value) {
                // ใช้ตัวที่ใหญ่ที่สุดที่ชนะได้
                result[idx] = nums1[right];
                right--;
            } else {
                // ใช้ตัวที่เล็กที่สุด (แพ้แน่ๆ)
                result[idx] = nums1[left];
                left++;
            }
        }
        
        return result;
    }
};