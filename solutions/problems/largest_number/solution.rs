impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut nums = nums;
        nums.sort_by(|&a, &b| {
            let ab = format!("{a}{b}");
            let ba = format!("{b}{a}");
            ba.cmp(&ab)
        });
        if (nums[0] == 0) {
            return String::from("0");
        }
        nums.iter().map(|num| num.to_string()).collect()
    }
}