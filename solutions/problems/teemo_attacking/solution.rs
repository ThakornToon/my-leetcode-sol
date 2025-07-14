impl Solution {
    pub fn find_poisoned_duration(time_series: Vec<i32>, duration: i32) -> i32 {
        let mut count = 0;
        let mut start = 0;
        for time in time_series {
            start = start.max(time);
            if (time + duration - start) > 0 {
                count += (time + duration - start);
            }
            start = time + duration;
        }
        return count;
    }
}