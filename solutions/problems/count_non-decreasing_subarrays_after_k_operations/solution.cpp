class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // เก็บ index ของค่าใน nums ที่ลดลงจาก front ไป back ใช้เก็บค่า max ที่เป็นไปได้ใน window ต่างๆ
        long long cost = 0, ans = 0;
        int R = n - 1;  // ขอบขวาของ window (ฝั่งที่หด)

        for (int L = n - 1; L >= 0; L--) {  // ขอบซ้ายของ window (ฝั่งที่ขยาย)
            // เพิ่ม nums[L] โดย pop_back ถ้าค่าใน dq <= nums[L](ต้องปรับค่า)
            while (!dq.empty() && nums[dq.back()] <= nums[L]) {  // ใช้ '=' ด้วยเพราะไม่เก็บซ้ำ
                int j = dq.back();
                dq.pop_back();
                int prev = dq.empty() ? R + 1 : dq.back();
                // จาก L..=R ค่าต้องไม่ลด
                // ปรับค่าตั้งแต่ j..prev ซึ่งมีค่า = nums[j] แต่ <= nums[L]
                cost += (long long)(nums[L] - nums[j]) * (prev - j);
            }
            dq.push_back(L);

            // หด window จนกว่า cost <= k
            while (cost > k) {
                cost -= nums[dq.front()] - nums[R];
                if (dq.front() == R) dq.pop_front();
                R--;
            }

            // จำนวน sub arry ที่เริ่มที่ L
            ans += R - L + 1;
        }

        return ans;
    }
};