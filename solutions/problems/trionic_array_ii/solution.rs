impl Solution {
    pub fn max_sum_trionic(nums: Vec<i32>) -> i64 {
        let mut inc1 = nums[0] as i64;
        let mut have_inc1 = 0;
        let mut dec = 0i64;
        let mut have_dec = 0;
        let mut inc2 = 0i64;
        let mut have_inc2 = 0;
        let mut max_sum = i64::MIN;

        for i in 1..nums.len() {
            if nums[i] < nums[i - 1] {
                if have_inc1 != 0 {
                    dec = inc1 + nums[i] as i64;
                    have_dec = 1;
                } else if have_dec != 0 {
                    dec += nums[i] as i64;
                    have_dec = 1;
                }

                inc1 = nums[i] as i64;
                have_inc1 = 0;
                inc2 = 0;
                have_inc2 = 0;
            } else if nums[i] > nums[i - 1] {
                if have_dec != 0 {
                    inc2 = dec + nums[i] as i64;
                    have_inc2 = 1;
                    max_sum = if max_sum > inc2 { max_sum } else { inc2 };
                } else if have_inc2 != 0 {
                    inc2 += nums[i] as i64;
                    have_inc2 = 1;
                    max_sum = if max_sum > inc2 { max_sum } else { inc2 };
                }

                let option1 = inc1 + nums[i] as i64;
                let option2 = nums[i - 1] as i64 + nums[i] as i64;
                inc1 = if option1 > option2 { option1 } else { option2 };
                have_inc1 = 1;
                dec = 0;
                have_dec = 0;
            } else {
                inc1 = nums[i] as i64;
                dec = 0;
                have_dec = 0;
                inc2 = 0;
                have_inc2 = 0;
            }
        }

        max_sum
    }
}