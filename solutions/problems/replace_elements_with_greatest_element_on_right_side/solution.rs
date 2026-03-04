impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        let n = arr.len();
        let mut max_right = -1;
        
        // วนจากขวาไปซ้าย
        for i in (0..n).rev() {
            let current = arr[i];
            arr[i] = max_right;
            max_right = max_right.max(current);
        }
        
        arr
    }
}