class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back((double)card);
        }
        return solve(nums);
    }
    
private:
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        
        // เลือกเลข 2 ตัวมาทำ operation
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {                
                vector<double> next_nums;
                // เก็บเลขที่ไม่ได้ใช้
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        next_nums.push_back(nums[k]);
                    }
                }
                double a = nums[i];
                double b = nums[j];

                // Apply all possible operations and recurse
                // 1. a + b
                next_nums.push_back(a + b);
                if (solve(next_nums)) return true;
                next_nums.pop_back(); // backtrack

                // 2. a * b
                next_nums.push_back(a * b);
                if (solve(next_nums)) return true;
                next_nums.pop_back(); // backtrack

                // 3. a - b
                next_nums.push_back(a - b);
                if (solve(next_nums)) return true;
                next_nums.pop_back(); // backtrack

                // 4. b - a
                next_nums.push_back(b - a);
                if (solve(next_nums)) return true;
                next_nums.pop_back(); // backtrack

                // 5. a / b
                if (abs(b) > 1e-6) {
                    next_nums.push_back(a / b);
                    if (solve(next_nums)) return true;
                    next_nums.pop_back(); // backtrack
                }

                // 6. b / a
                if (abs(a) > 1e-6) {
                    next_nums.push_back(b / a);
                    if (solve(next_nums)) return true;
                    next_nums.pop_back(); // backtrack
                }
            }
        }
        return false;
    }
};