class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            // primary diagonal: แถว i คอลัมน์ i
            sum += mat[i][i];
            
            // secondary diagonal: แถว i คอลัมน์ n-1-i
            // ป้องกันการนับซ้ำกรณี i == n-1-i (ตรงกลาง)
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }
        
        return sum;
    }
};