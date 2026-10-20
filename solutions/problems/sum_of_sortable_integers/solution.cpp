class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool possible = true;
            int prev_max = -1;

            for (int i = 0; i < n; i += k) {
                // ตรวจสอบว่าบล็อกขนาด k นี้สามารถหมุนให้เรียงได้หรือไม่
                int drop_count = 0;
                int min_val = nums[i], max_val = nums[i];
                
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    if (j > 0 && nums[i + j - 1] > curr) {
                        drop_count++;
                    }
                }
                if (nums[i + k - 1] > nums[i]) {
                    drop_count++;
                }

                // ถ้ามีจุดที่ลดมากกว่า 1 ครั้ง แสดงว่าหมุนวนให้เรียงไม่ได้
                if (drop_count > 1) {
                    possible = false;
                    break;
                }

                // หาค่าต่ำสุดและสูงสุดของบล็อกนี้เพื่อเช็คความสัมพันธ์กับบล็อกก่อนหน้า
                int b_min = nums[i], b_max = nums[i];
                // หาตำแหน่งเริ่มต้นที่แท้จริงหากมีการวนรอบ
                int start_idx = i;
                for (int j = 1; j < k; ++j) {
                    if (nums[i + j] < nums[i + j - 1]) {
                        start_idx = i + j;
                        break;
                    }
                }
                
                int first_val = nums[start_idx];
                int last_val = nums[i + (start_idx - i - 1 + k) % k]; // ตัวก่อนหน้า start_idx

                if (prev_max > first_val) {
                    possible = false;
                    break;
                }
                // อัปเดตค่าสูงสุดของบล็อกปัจจุบัน
                prev_max = nums[i + (start_idx - i + k - 1) % k];
            }

            if (possible) {
                total_sum += k;
            }
        }
        return total_sum;
    }
};