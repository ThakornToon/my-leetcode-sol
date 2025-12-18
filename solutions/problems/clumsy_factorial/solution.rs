impl Solution {
    pub fn clumsy(n: i32) -> i32 {
        if n <= 4 {
            return match n {
                1 => 1,
                2 => 2,
                3 => 6,
                4 => 7,
                _ => 0,
            };
        }
        
        let mut result = n * (n - 1) / (n - 2) + (n - 3);
        let mut n = n - 4;
        
        while n >= 4 {
            result -= n * (n - 1) / (n - 2) - (n - 3);
            n -= 4;
        }
        
        // Handle remaining terms
        match n {
            0 => result,
            1 => result - 1,
            2 => result - 2,
            3 => result - 6,
            _ => result,
        }
    }
}