class Solution {
private:
    bool backtrack(vector<int>& nums, vector<bool>& visited, int k, int target, int curr_sum, int start_idx) {
        if (k == 1) return true; // หากแบ่งได้ k-1 กลุ่มแล้ว กลุ่มสุดท้ายที่เหลือจะถูกต้องโดยอัตโนมัติ

        // หากลุ่มถัดไปจากเลขที่ไม่ได้ใช้ต่อ
        if (curr_sum == target) {
            return backtrack(nums, visited, k - 1, target, 0, 0);
        }

        // ลองเลือกตัวเลขที่ตำแหน่งต่างๆมาใช้
        for (int i = start_idx; i < nums.size(); ++i) {
            if (!visited[i]) {
                if (curr_sum + nums[i] <= target) {
                    visited[i] = true;
                    if (backtrack(nums, visited, k, target, curr_sum + nums[i], i + 1)) {
                        return true;
                    }
                    visited[i] = false;
                }
                
                // Pruning: กรณีเริ่มต้นกลุ่มใหม่แล้วตัวแรกที่มากสุดที่เหลืออยู่ไม่ผ่าน ยังไงก็ผิดแน่นอนเพราะยังไงตัวนั้นก็ต้องมีกลุ่มอยู่ แต่ถ้าเป็นค่าที่สองเป็นต้นไปอาจอยู่หรือไม่ก็ได้
                if (curr_sum == 0) break;
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // Greedy ไม่ได้ เช่น [4, 3, 3, 2, 2, 2] k=2
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

        sort(nums.rbegin(), nums.rend());  // เรียงมากไปน้อยเพื่อ puring ที่ดีกว่า
        if (nums[0] > target) return false;

        vector<bool> visited(nums.size(), false);
        return backtrack(nums, visited, k, target, 0, 0);
    }
};