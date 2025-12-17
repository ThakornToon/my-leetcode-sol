impl Solution {
    pub fn broken_calc(start_value: i32, target: i32) -> i32 {
        let mut target = target;
        let mut operations = 0;
        
        while target > start_value {
            if target % 2 == 0 {
                target /= 2;
            } else {
                target += 1;
            }
            operations += 1;
        }
        
        operations + (start_value - target)
    }
}