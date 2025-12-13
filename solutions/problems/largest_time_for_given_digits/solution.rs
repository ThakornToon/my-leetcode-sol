impl Solution {
    pub fn largest_time_from_digits(arr: Vec<i32>) -> String {
        let mut digits = arr.clone();
        digits.sort_by(|a, b| b.cmp(a));
        
        // พยายามสร้างชั่วโมงให้มากที่สุด
        for i in 0..4 {
            for j in 0..4 {
                if i == j { continue; }
                for k in 0..4 {
                    if k == i || k == j { continue; }
                    let l = 6 - i - j - k;
                    
                    let hours = digits[i] * 10 + digits[j];
                    let minutes = digits[k] * 10 + digits[l];
                    
                    if hours < 24 && minutes < 60 {
                        return format!("{}{}:{}{}", digits[i], digits[j], digits[k], digits[l]);
                    }
                }
            }
        }
        
        String::new()
    }
}