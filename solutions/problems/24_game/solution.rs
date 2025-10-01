impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        let nums: Vec<f64> = cards.iter().map(|&x| x as f64).collect();
        Self::dfs(&nums)
    }
    
    fn dfs(nums: &[f64]) -> bool {
        let n = nums.len();
        if n == 1 {
            return (nums[0] - 24.0).abs() < 1e-6;
        }
        
        for i in 0..n {
            for j in 0..n {
                if i == j {
                    continue;
                }
                
                // Collect unused numbers
                let mut next_nums: Vec<f64> = Vec::new();
                for k in 0..n {
                    if k != i && k != j {
                        next_nums.push(nums[k]);
                    }
                }
                
                // Try all operations
                let a = nums[i];
                let b = nums[j];
                let operations = [
                    a + b,
                    a - b,
                    a * b,
                    if b.abs() > 1e-6 { a / b } else { 0.0 }
                ];
                
                for op in 0..4 {
                    if op == 3 && b.abs() < 1e-6 {
                        continue;
                    }
                    
                    next_nums.push(operations[op]);
                    if Self::dfs(&next_nums) {
                        return true;
                    }
                    next_nums.pop();
                }
            }
        }
        false
    }
}