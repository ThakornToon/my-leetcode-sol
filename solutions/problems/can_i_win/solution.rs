use std::collections::HashMap;

impl Solution {
    pub fn can_i_win(max_choosable_integer: i32, desired_total: i32) -> bool {
        if desired_total <= 0 { return true; }
        if max_choosable_integer * (max_choosable_integer + 1) / 2 < desired_total { return false; }
        if max_choosable_integer >= desired_total { return true; }
        
        let mut memo = HashMap::new();
        
        fn backtrack(max_num: i32, target: i32, used: i32, memo: &mut HashMap<i32, bool>) -> bool {
            if let Some(&result) = memo.get(&used) {
                return result;
            }
            
            for i in 0..max_num {
                if (used & (1 << i)) == 0 {
                    let current = i + 1;
                    if current >= target || !backtrack(max_num, target - current, used | (1 << i), memo) {
                        memo.insert(used, true);
                        return true;
                    }
                }
            }
            
            memo.insert(used, false);
            false
        }
        
        backtrack(max_choosable_integer, desired_total, 0, &mut memo)
    }
}