class Solution {
private:
    // นับจำนวนคู่ (j, k) ที่ j < k และ product = target
    long long countPairs(vector<int>& arr, long long target) {
        unordered_map<long long, int> freq;
        long long count = 0;
        
        for (int j = 0; j < arr.size(); j++) {
            // ตรวจสอบว่ามีค่า target / arr[j] ใน map หรือไม่
            if (target % arr[j] == 0) {
                long long need = target / arr[j];
                if (freq.count(need)) {
                    count += freq[need];
                }
            }
            // เพิ่ม arr[j] ลงใน map
            freq[arr[j]]++;
        }
        
        return count;
    }
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long result = 0;
        
        // กรณีที่ 1: nums1[i]^2 = nums2[j] * nums2[k]
        for (int i = 0; i < nums1.size(); i++) {
            long long target = (long long)nums1[i] * nums1[i];
            result += countPairs(nums2, target);
        }
        
        // กรณีที่ 2: nums2[j]^2 = nums1[i] * nums1[k]
        for (int j = 0; j < nums2.size(); j++) {
            long long target = (long long)nums2[j] * nums2[j];
            result += countPairs(nums1, target);
        }
        
        return (int)result;
    }
};