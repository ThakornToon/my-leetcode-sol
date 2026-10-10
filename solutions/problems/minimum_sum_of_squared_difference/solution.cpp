class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total_k = (long long)k1 + k2;
        map<int, long long, greater<int>> count;  // {diff, freq} เรียงตาม key มากไปน้อย
        
        long long total_diff = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            count[d]++;
            total_diff += d;
        }
        
        // ถ้าโควตาสามารถลดผลต่างทั้งหมดให้เป็น 0 ได้ ผลรวมกำลังสองจะเป็น 0 ทันที
        if (total_diff <= total_k) return 0;
        
        // หากไม่มีโควตาเหลือแล้ว ไม่ต้องคำนวณต่อ
        if (total_k == 0) {
            long long ans = 0;
            for (const auto& [d, freq] : count) {
                ans += freq * (long long)d * d;
            }
            return ans;
        }

        // การปรับ diff ตัวมากจะดีกว่าการปรัับ diff ตัวน้อย
        for (auto it = count.begin(); it != count.end(); ++it) {
            int d = it->first;
            long long freq = it->second;
            if (d == 0) continue;
            
            // ดูค่า diff ที่ควรปรับรองลงมาว่ามีค่าเท่าไร
            auto next_it = std::next(it);
            int next_d = (next_it == count.end()) ? 0 : next_it->first;
            
            // diff val ที่ปรับได้ของปัจจุบัน
            long long diff_val = d - next_d;
            long long total_reduction_needed = diff_val * freq;
            
            // ลด diff ปัจจุบันจน = next diff เท่าที่ทำได้
            if (total_k >= total_reduction_needed) {
                total_k -= total_reduction_needed;
                count[next_d] += freq;
                it->second = 0;
            } else {
                long long reduce_each = total_k / freq;  // ลดทุกตัวให้เท่าๆกัน
                long long remainder = total_k % freq;  // เศษ
                
                if (reduce_each == 0) {
                    // กรณีโควตาน้อยกว่าจำนวนความถี่ ลดลง 1 หน่วยเฉพาะบางตัว
                    it->second -= total_k;
                    count[d - 1] += total_k;
                } else {
                    count[d - reduce_each] += freq - remainder;
                    count[d - reduce_each - 1] += remainder;
                    it->second = 0;
                }

                total_k = 0;
                break;
            }
        }
        
        long long ans = 0;
        for (const auto& [d, freq] : count) {
            ans += freq * (long long)d * d;
        }
        return ans;
    }
};