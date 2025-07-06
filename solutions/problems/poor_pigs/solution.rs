impl Solution {
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let tests = minutes_to_test / minutes_to_die;
        let mut pigs = 0;
        let mut sum = 1;
        while sum < buckets {
            sum *= (tests + 1);
            pigs += 1;
        }
        pigs
    }
}