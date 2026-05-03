impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut count = 0 as i32;
        
        for i in 0..n {
            let mut xorVal = 0;
            for k in i..n {
                xorVal ^= arr[k];
                if xorVal == 0 {
                    count += (k - i) as i32;
                }
            }
        }
        
        return count;
    }
}