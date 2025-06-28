impl Solution {
    pub fn kth_smallest(matrix: Vec<Vec<i32>>, k: i32) -> i32 {
        let n = matrix.len();
        let mut left = matrix[0][0];
        let mut right = matrix[n-1][n-1];
        
        while left < right {
            let mid = left + (right - left) / 2;
            let mut count = 0;
            let mut col = n - 1;
            
            for row in 0..n {
                while col > 0 && matrix[row][col] > mid {
                    col -= 1;
                }
                if matrix[row][col] <= mid {
                    count += (col + 1) as i32;
                }
            }
            
            if count < k {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        left
    }
}