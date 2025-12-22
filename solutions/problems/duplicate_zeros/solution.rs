impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let n = arr.len();
        let mut zeros_count = 0;
        
        // First pass: count zeros
        for &num in arr.iter() {
            if num == 0 {
                zeros_count += 1;
            }
        }
        
        if zeros_count == 0 {
            return;
        }
        
        // Second pass: copy from the end
        let mut i = n - 1;
        let mut j = n + zeros_count - 1;
        
        while i >= 0 {
            if j < n {
                arr[j] = arr[i];
            }
            
            if arr[i] == 0 {
                if j > 0 {
                    j -= 1;
                    if j < n {
                        arr[j] = 0;
                    }
                }
            }
            
            if i == 0 {
                break;
            }
            if i > 0 {
                i -= 1;
            }
            if j > 0 {
                j -= 1;
            }
        }
    }
}