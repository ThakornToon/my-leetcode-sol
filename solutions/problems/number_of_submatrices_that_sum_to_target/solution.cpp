class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        // คำนวณ prefix sum สำหรับแต่ละคอลัมน์
        vector<vector<int>> col_prefix(m + 1, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= m; i++) {
                col_prefix[i][j] = matrix[i-1][j] + col_prefix[i-1][j];
            }
        }

        // ใช้เทคนิคจากปัญหา 1D แต่คราวนี้สำหรับแต่ละคู่แถว
        for (int r1 = 1; r1 <= m; r1++) {
            for (int r2 = r1; r2 <= m; r2++) {
                unordered_map<int, int> prefix_counts;
                prefix_counts[0] = 1;
                int current_sum = 0;

                for (int j = 0; j < n; j++) {
                    // ผลรวมของคอลัมน์ j จากแถว r1 ถึง r2
                    int col_sum = col_prefix[r2][j] - col_prefix[r1-1][j];
                    current_sum += col_sum;

                    // ตรวจสอบว่าเคยมีผลรวม (current_sum - target) หรือไม่
                    if (prefix_counts.find(current_sum - target) != prefix_counts.end()) {
                        count += prefix_counts[current_sum - target];
                    }

                    // บันทึกผลรวมปัจจุบัน
                    prefix_counts[current_sum]++;
                }
            }
        }

        return count;
    }
};