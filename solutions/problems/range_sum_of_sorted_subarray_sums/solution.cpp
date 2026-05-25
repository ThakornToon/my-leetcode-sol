class Solution {
private:
    const int MOD = 1000000007;
    
    // นับจำนวน subarray ที่มี sum <= target และผลรวมของ subarray เหล่านั้น
    pair<int, long long> countAndSum(vector<int>& prefix, vector<int>&  prefixPrefix, int n, int target) {
        int count = 0;  // จำนวน subarray ที่มี sum <= target
        long long total = 0;  // ผลรวมของ subarray sums เหล่านั้น
        
        // sliding window
        for (int i = 0, j = 0; i < n; i++) {
            // ขึง j จนสุด
            while (j < n && prefix[j+1] - prefix[i] <= target) {
                j++;
            }
            // ผลรวมของ subarray sums i..=j-1
            // [1, 3, 4] -> {(1) + (1+3) + (1+3+4)} + {(3) + (3+4)} + {(4)}
            // prefix = [0, 1, 4, 8], prefixPrefix = [0, 0, 1, 5, 13]
            int windowSum = (prefixPrefix[j+1] - prefixPrefix[i+1]) - (j - i) * prefix[i];

            count += j - i;
            total += windowSum;
        }
        
        // {จำนวน subarray ที่มี sum <= target, ผลรวมของ subarray เหล่านั้น}
        return {count, total};
    }
    
    // binary search หาค่า k-th smallest sum
    int kthSum(vector<int>& prefix, vector<int>& prefixPrefix, int n, int k) {
        int left = 0, right = 100000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            auto [cnt, _] = countAndSum(prefix, prefixPrefix, n, mid);  // จำนวน subarray ที่ <= mid
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // ค่า subarray ที่ลำดับ k
        return left;
    }

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // prefix sum สะสมซ้อนอีกทีเพื่อใช้ช่วยคำนวณ
        vector<int> prefixPrefix(n + 2, 0);
        for (int i = 1; i <= n + 1; i++) {
            prefixPrefix[i] = prefixPrefix[i - 1] + prefix[i - 1];
        }
        
        // หาค่า subarray ที่ right แล้วหาผลรวม subarray ที่ <= subarray นั้น
        int last = kthSum(prefix, prefixPrefix, n, right);
        auto [cntR, sumR] = countAndSum(prefix, prefixPrefix, n, last);
        
        // หาค่า subarray ที่ left แล้วหาผลรวม subarray ที่ <= subarray นั้น
        int first = kthSum(prefix, prefixPrefix, n, left - 1);
        auto [cntL, sumL] = countAndSum(prefix, prefixPrefix, n, first);

        long long result = sumR;
        // กรณีค่า subarry ซ้ำกับตำแหน่ง right แต่อยู่หลังจาก right
        result = (result - (long long)last * (cntR - right)) % MOD;
        result = (result - sumL) % MOD;
        // กรณีค่า subarry ซ้ำกับตำแหน่ง left แต่อยู่ข้างหน้า left
        result = (result + (long long)first * (cntL - (left - 1))) % MOD;
        
        return (result + MOD) % MOD;
    }
};