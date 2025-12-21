impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let n = customers.len();
        let minutes = minutes as usize;
        
        // Calculate base satisfied customers
        let mut base_satisfied = 0;
        for i in 0..n {
            if grumpy[i] == 0 {
                base_satisfied += customers[i];
            }
        }
        
        // Sliding window to find best minutes
        let mut max_additional = 0;
        let mut current_additional = 0;
        
        // First window
        for i in 0..minutes {
            if grumpy[i] == 1 {
                current_additional += customers[i];
            }
        }
        max_additional = current_additional;
        
        // Slide the window
        for i in minutes..n {
            // Remove leftmost
            if grumpy[i - minutes] == 1 {
                current_additional -= customers[i - minutes];
            }
            // Add rightmost
            if grumpy[i] == 1 {
                current_additional += customers[i];
            }
            max_additional = max_additional.max(current_additional);
        }
        
        base_satisfied + max_additional
    }
}