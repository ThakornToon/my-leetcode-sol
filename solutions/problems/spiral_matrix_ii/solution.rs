

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut res = vec![vec![0; n]; n];
        let mut count = 0;
        let (mut top, mut bottom, mut left, mut right) = (0, n - 1, 0, n - 1);
        while top <= bottom && left <= right {
            for i in left..=right {
                count += 1;
                res[top][i] = count;
            }
            top += 1;
            if top > bottom {
                break;
            }
            for i in top..=bottom {
                count += 1;
                res[i][right] = count;
            }
            right -= 1;
            for i in (left..=right).rev() {
                count += 1;
                res[bottom][i] = count;
            }
            bottom -= 1;
            if top > bottom {
                break;
            }
            for i in (top..=bottom).rev() {
                count += 1;
                res[i][left] = count;
            }
            left += 1;
        }
        res
    }
}