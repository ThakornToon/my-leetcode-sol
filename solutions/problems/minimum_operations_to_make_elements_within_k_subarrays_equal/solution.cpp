class Solution {
private:
    // คำนวณ ops ที่ใช้ในการทำหน้าต่างขนาด x ให้เท่ากันทั้งหมด (ค่า Median)
    vector<long long> getMinOps(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> res(n, 0);
        multiset<int> lower, upper;  // แบ่งส่วนครึ่งซ้ายขวาเพื่อหา Median คิดได้ง่าย
        long long lower_sum = 0, upper_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            // เมื่อมีค่าใหม่เพิ่มมาให้ดูว่าควรอยู่ซ้ายหรือขวา
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lower_sum += nums[i];
            } else {
                upper.insert(nums[i]);
                upper_sum += nums[i];
            }
            
            // ปรับขนาด window รวม
            if (i >= x) {
                int out = nums[i - x];
                auto it = lower.find(out);
                if (it != lower.end()) {
                    lower.erase(it);
                    lower_sum -= out;
                } else {
                    it = upper.find(out);
                    if (it != upper.end()) {
                        upper.erase(it);
                        upper_sum -= out;
                    }
                }
            }
            
            // ปรับขนาดของ multiset ทั้งสองฝั่ง
            // lower.size() จะมีขนาดมากกว่า upper.size() อยู่ไม่เกิน 1
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upper_sum -= val;
                lower_sum += val;
            } else if (lower.size() - upper.size() > 1) {
                // เอา lower มาใส่ upper
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lower_sum -= val;
                upper_sum += val;
            }
            
            // ขนาด window = x ถึงสามารถบันทึจำนวน ops ได้
            if (i >= x - 1) {
                // median ไม่อยู่ใน lower ก็เป็นค่าระหว่าง lower กับ upper
                // ถ้า median อยู่ระหว่าง [max(lower), min(upper)] ใช้ค่าไหน ops ก็เท่ากันเพราะเป็นจุดสมดุล
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lower_sum) + (upper_sum - median * upper.size());
                res[i] = ops;  // จำนวน ops เมื่อ window ขนาด x จบที่ index i
            }
        }
        return res;
    }

    // DP
    long long DP(int idx, int rem_k, int x, int n, vector<long long>& min_ops, vector<vector<long long>>& memo) {
        if (rem_k == 0) return 0;  // ดูจำนวน k ที่ยังต้องการ
        if (idx + rem_k * x > n) return LLONG_MAX;  // จำนวนสมาชิกที่เหลือไม่พอกับค่า k ที่ต้องการ
        if (memo[idx][rem_k] != -1) return memo[idx][rem_k];  // เคยคิดมาแล้ว(มี Ans อยู่แล้ว)
        
        // เลือกข้าม window ที่เริ่มที่ idx
        long long skip = DP(idx + 1, rem_k, x, n, min_ops, memo);
        
        // เลือก window ขนาด x เริ่มที่ตำแหน่ง idx (จบที่ idx + x - 1) แล้วคิดต่อ
        long long pick = min_ops[idx + x - 1] + DP(idx + x, rem_k - 1, x, n, min_ops, memo);
        
        // dp[idx][rem_k] = ops ที่น้อยสุด พิจารณาระหว่างการเลือก window ณ ตอนนี้เลยหรือไปเลือกในภายหลัง โดยปัจจุบันต้องการ rem_k
        return memo[idx][rem_k] = min(skip, pick);
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> min_ops = getMinOps(nums, x);
        
        // สร้าง Memoization Table เริ่มต้นด้วย -1
        vector<vector<long long>> memo(n + 1, std::vector<long long>(k + 1, -1));
        
        return DP(0, k, x, n, min_ops, memo);
    }
};