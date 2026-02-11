impl Solution {
    pub fn reconstruct_matrix(upper: i32, lower: i32, colsum: Vec<i32>) -> Vec<Vec<i32>> {
        let n = colsum.len();
        let mut result = vec![vec![0; n], vec![0; n]];
        let mut up = upper;
        let mut low = lower;
        
        // 1. ใส่ colsum=2 ก่อน
        for i in 0..n {
            if colsum[i] == 2 {
                result[0][i] = 1;
                result[1][i] = 1;
                up -= 1;
                low -= 1;
            }
        }
        
        // 2. ใส่ colsum=1
        for i in 0..n {
            if colsum[i] == 1 {
                if up > 0 {
                    result[0][i] = 1;
                    up -= 1;
                } else if low > 0 {
                    result[1][i] = 1;
                    low -= 1;
                } else {
                    return vec![];  // ล้มเหลว
                }
            }
        }
        
        // 3. ตรวจสอบ
        if up != 0 || low != 0 {
            return vec![];
        }
        
        result
    }
}