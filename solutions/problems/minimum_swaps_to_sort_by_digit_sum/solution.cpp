class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        struct Element {
            int digit_sum;
            int val;
            int original_idx;
        };

        vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        // เรียงลำดับตาม Digit Sum จากนั้นตามด้วย Value
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) return a.digit_sum < b.digit_sum;
            return a.val < b.val;
        });

        vector<bool> visited(n, false);
        int total_swaps = 0;

        for (int i = 0; i < n; ++i) {
            // ถ้าเคยเยี่ยมชมแล้ว หรือตัวเลขอยู่ที่ตำแหน่งถูกต้องแล้ว
            if (visited[i] || arr[i].original_idx == i) {
                continue;
            }

            // สลับระหว่างตำแหน่ง curr กับ arr[curr].original_idx ใน nums จะได้ว่าตำแหน่ง curr จะถูกแต่ arr[curr].original_idx อาจต้องสลับต่อ ทำจนเกิดวงรอบหรือสลับต่อไม่ได้
            int cycle_size = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].original_idx;
                cycle_size++;
            }

            if (cycle_size > 1) {
                total_swaps += (cycle_size - 1);
            }
        }

        return total_swaps;
    }
};