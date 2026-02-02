class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<int> smaller, window;
        long long sum_smaller = 0;
        long long min_total = LLONG_MAX;
        
        // เริ่มจาก i1 = 1
        int i1 = 1;
        int window_end = min(i1 + dist, n-1);
        
        // เติม elements เริ่มต้น
        for (int j = i1 + 1; j <= window_end; j++) {
            window.insert(nums[j]);
        }
        
        // ย้าย k-2 elements ที่น้อยที่สุดไป smaller
        while (smaller.size() < k-2 && !window.empty()) {
            auto it = window.begin();
            sum_smaller += *it;
            smaller.insert(*it);
            window.erase(it);
        }
        
        if (smaller.size() == k - 2) {
            min_total = min(min_total, nums[0] + nums[i1] + sum_smaller);
        }

        // เลื่อน i1
        for (i1 = 2; i1 < n - (k - 2); i1++) {
            // 1. ลบ nums[i1] ที่ออกจาก window
            int old_val = nums[i1];  // ออกจาก window
            int new_window_end = min(i1 + dist, n-1);
            
            // ลบ old_val จาก smaller หรือ larger
            auto it_s = smaller.find(old_val);
            if (it_s != smaller.end()) {  // หาใน smaller เจอ
                sum_smaller -= old_val;
                smaller.erase(it_s);
            } else {
                auto it_l = window.find(old_val);
                if (it_l != window.end()) {
                    window.erase(it_l);
                }
            }
            
            // 2. เพิ่ม elements ใหม่ถ้า new_window_end > old_window_end
            int old_window_end = min(i1-1 + dist, n-1);
            if (new_window_end > old_window_end) {
                int new_val = nums[new_window_end];
                if (!smaller.empty() && new_val < *smaller.rbegin()) { 
                    smaller.insert(new_val);
                    sum_smaller += new_val;
                } else {
                    window.insert(new_val);
                }
            }
            
            // 3. ปรับ smaller ให้มี k-2 elements
            // ถ้า smaller มากเกินไป: ย้ายกลับไป larger
            while (smaller.size() > k-2) {
                auto it = prev(smaller.end());
                sum_smaller -= *it;
                window.insert(*it);
                smaller.erase(it);
            }

            // ถ้า smaller น้อยเกินไป: ย้ายจาก window มา
            while (smaller.size() < k-2 && !window.empty()) {
                auto it = window.begin();
                sum_smaller += *it;
                smaller.insert(*it);
                window.erase(it);
            }
            
            // 4. บันทึกผลลัพธ์
            if (smaller.size() == k-2) {
                min_total = min(min_total, nums[0] + nums[i1] + sum_smaller);
            }
        }
        
        return min_total;
    }
};