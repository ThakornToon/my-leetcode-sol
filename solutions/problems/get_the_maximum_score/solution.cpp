class Solution {
private:
    const int MOD = 1000000007;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Prefix sums
        vector<long long> prefix1(n + 1, 0);
        vector<long long> prefix2(m + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix1[i + 1] = prefix1[i] + nums1[i];
        }
        for (int i = 0; i < m; i++) {
            prefix2[i + 1] = prefix2[i] + nums2[i];
        }
        
        // หาค่า connect values พร้อมตำแหน่งใน nums2 (ใช้ binary search)
        vector<pair<int, int>> connect; // {index nums1, index nums2}
        
        for (int i = 0; i < n; i++) {
            int val = nums1[i];
            // binary search หา index val ใน nums2
            int pos = lower_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            if (pos < m && nums2[pos] == val) {
                connect.push_back({i, pos});
            }
        }
        
        long long result = 0;
        int lastIdx1 = 0, lastIdx2 = 0;
        
        // สำหรับแต่ละ connect value
        for (auto& [idx1, idx2] : connect) {
            // ผลรวมจาก connect value ก่อนหน้าถึง connect value นี้ (ไม่รวมตัว connect)
            long long sum1 = prefix1[idx1 + 1] - prefix1[lastIdx1];
            long long sum2 = prefix2[idx2 + 1] - prefix2[lastIdx2];
            
            // เลือกเส้นทางที่ดีกว่า แล้วบวก connect value (จะถูกนับแค่ครั้งเดียว)
            result += max(sum1, sum2);
            result %= MOD;
            
            lastIdx1 = idx1 + 1;
            lastIdx2 = idx2 + 1;
        }
        
        // ส่วนสุดท้ายหลังจาก connect value สุดท้าย
        long long sum1 = prefix1[n] - prefix1[lastIdx1];
        long long sum2 = prefix2[m] - prefix2[lastIdx2];
        result += max(sum1, sum2);
        result %= MOD;
        
        return (int)result;
    }
};