class Solution {
private: 
    // สร้างผลรวม subsequence ทั้งหมด
    vector<int> generateSums(vector<int>& nums, int start, int end) {
        int n = end - start;
        vector<int> sums(1 << n, 0);
        
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[start + i];
                }
            }
            sums[mask] = sum;
        }
        
        return sums;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        
        // สร้างผลรวมของแต่ละครึ่ง
        vector<int> sums1 = generateSums(nums, 0, mid);
        vector<int> sums2 = generateSums(nums, mid, n);
        
        // เรียงลำดับครึ่งหลัง
        sort(sums2.begin(), sums2.end());
        
        int ans = INT_MAX;
        
        for (int sum1 : sums1) {
            int target = goal - sum1;
            
            // binary search หาค่าใกล้เคียง >= target
            auto it = lower_bound(sums2.begin(), sums2.end(), target);
            
            if (it != sums2.end()) {
                ans = min(ans, abs(*it - target));
            }

            // ลองถอยไปค่าก่อนหน้าซึ่ง < target ว่าดีกว่าไหม
            if (it != sums2.begin()) {
                --it;
                ans = min(ans, abs(*it - target));
            }
            
            if (ans == 0) break;
        }
        
        return ans;
    }
};