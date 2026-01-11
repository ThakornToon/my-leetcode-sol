impl Solution {
    pub fn balanced_string(s: String) -> i32 {
let n = s.len();
        let k = n / 4;
        
        let mut count = [0; 4];
        for c in s.chars() {
            count[Self::idx(c)] += 1;
        }
        
        if count.iter().all(|&x| x == k) {
            return 0;
        }
        
        let chars: Vec<char> = s.chars().collect();
        let mut left = 0;
        let mut result = n as i32;
        let mut window = [0; 4];
        
        for right in 0..n {
            window[Self::idx(chars[right])] += 1;
            
            while left <= right {
                let mut valid = true;
                for i in 0..4 {
                    if count[i] - window[i] > k {
                        valid = false;
                        break;
                    }
                }
                
                if valid {
                    result = result.min((right - left + 1) as i32);
                    window[Self::idx(chars[left])] -= 1;
                    left += 1;
                } else {
                    break;
                }
            }
        }
        
        result
    }
    
    fn idx(c: char) -> usize {
        match c {
            'Q' => 0,
            'W' => 1,
            'E' => 2,
            'R' => 3,
            _ => unreachable!(),
        }
    }
}