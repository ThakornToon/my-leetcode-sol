impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        let k = k as usize;
        let mut chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        
        for i in (0..n).step_by(2 * k) {
            let left = i;
            let right = std::cmp::min(i + k - 1, n - 1);
            let mut l = left;
            let mut r = right;
            while l < r {
                chars.swap(l, r);
                l += 1;
                r -= 1;
            }
        }
        
        chars.into_iter().collect()
    }
}