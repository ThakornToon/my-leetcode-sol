impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {
        let mut first = None;
        let mut second = None;
        let mut third = None;
        
        for &num in nums.iter() {
            if Some(num) == first || Some(num) == second || Some(num) == third {
                continue; // ข้ามค่าซ้ำ
            }
            
            if first.is_none() || num > first.unwrap() {
                third = second;
                second = first;
                first = Some(num);
            } else if second.is_none() || num > second.unwrap() {
                third = second;
                second = Some(num);
            } else if third.is_none() || num > third.unwrap() {
                third = Some(num);
            }
        }
        
        third.unwrap_or(first.unwrap())
    }
}