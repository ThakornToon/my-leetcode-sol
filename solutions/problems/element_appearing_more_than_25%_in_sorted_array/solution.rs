impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let target_count = n / 4;
        let mut count = 1;
        
        for i in 1..n {
            if arr[i] == arr[i - 1] {
                count += 1;
                if count > target_count {
                    return arr[i];
                }
            } else {
                count = 1;
            }
        }
        
        arr[0]
    }
}