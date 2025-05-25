impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let mut top = 0;
        let mut bot = matrix.len() - 1;
        let col_size = matrix[0].len();
        while top <= bot {
            let mid = (top + bot) / 2;
            if matrix[mid][0] <= target && matrix[mid][col_size - 1] >= target {
                break;
            } 
            else if matrix[mid][0] > target {
                if mid == 0 {break;}
                bot = mid - 1;
            } 
            else {
                top = mid + 1;
            }
        }

        let row = (top + bot) / 2;
        let mut left = 0;
        let mut right = matrix[row].len() - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if matrix[row][mid] == target {
                return true;
            } 
            else if matrix[row][mid] > target {
                if mid == 0 {break;}
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        return false; 
    }
}