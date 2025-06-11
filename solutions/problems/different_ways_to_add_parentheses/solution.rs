impl Solution {
    fn calculate(num1: i32, num2: i32, sign: char) -> i32 {
        if sign == '+' {
            return num1 + num2;
        } else if sign == '-' {
            return num1 - num2;
        } else {
            return num1 * num2;
        }
    }
    fn find_all(exp: &Vec<char>, start: usize, end: usize) -> Vec<i32> {
        let mut all = Vec::new();
        
        for i in start..=end {
            let c = exp[i];
            if c == '+' || c == '-' || c == '*' {
                let left = Self::find_all(exp, start, i - 1);
                let right = Self::find_all(exp, i + 1, end);
                
                for &l in &left {
                    for &r in &right {
                        all.push(Self::calculate(l, r, c));
                    }
                }
            }
        }
        
        if all.is_empty() {
            let mut num = 0;
            for i in start..=end {
                num = (num * 10) + (exp[i] as i32 - 48);
            }
            all.push(num);
        }
        
        all
    }
    pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
        let exp: Vec<char> = expression.chars().collect();
        return Self::find_all(&exp, 0, expression.len() - 1);
    }
}