use std::collections::HashMap;
use std::cmp::min;
impl Solution {
    pub fn least_ops_express_target(x: i32, target: i32) -> i32 {
        let mut memo = HashMap::new();
        Self::dfs(x, target, &mut memo)
    }

    fn dfs(x: i32, target: i32, memo: &mut HashMap<i32, i32>) -> i32 {
        // Base case 1: ตรวจสอบ memo
        if let Some(&result) = memo.get(&target) {
            return result;
        }
        
        // Base case 2: x > target
        if x > target {
            // Option 1: target = x/x + x/x + ...
            let option1 = 2 * target - 1;
            // Option 2: x - (x - target) = x - (x/x + x/x + ...)
            let option2 = 2 * (x - target);
            let result = min(option1, option2);
            memo.insert(target, result);
            return result;
        }
        
        // Base case 3: x == target
        if x == target {
            memo.insert(target, 0);
            return 0;
        }
        
        // หา x^n ที่น้อยที่สุดที่ >= target
        let mut prod = x as i64;
        let mut n = 0; // x * x * x * ... = x^n ops
        
        while prod < target as i64 {
            prod *= x as i64;
            n += 1;
        }
        
        // กรณีพอดี
        if prod == target as i64 {
            memo.insert(target, n);
            return n;
        }
        
        // ทางเลือก 1: target = x^(n-1) + remainder1  
        let prev_prod = prod / x as i64;
        let mut ans = n + Self::dfs(x, (target as i64 - prev_prod) as i32, memo); // x^n + remainder1
        
        // ทางเลือก 2: target = x^n - excess พิจารณาเมื่อเศษ excess < target
        // ป้องกัน infinite recursion ปัญหาจะใหญ่ขึ้นแทนและแย่กว่าแน่นอน
        if prod < 2 * target as i64 { 
            ans = ans.min(Self::dfs(x, (prod - target as i64) as i32, memo) + n + 1);
        }

        memo.insert(target, ans);
        ans
    }
}