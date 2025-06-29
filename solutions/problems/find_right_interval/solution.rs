impl Solution {
    pub fn find_right_interval(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        let mut starts: Vec<(i32, usize)> = intervals.iter().enumerate()
            .map(|(i, interval)| (interval[0], i))
            .collect();
        
        starts.sort_by_key(|&(start, _)| start);
        
        let mut result = Vec::with_capacity(intervals.len());
        
        for interval in intervals {
            let end = interval[1];
            let mut left = 0;
            let mut right = starts.len();
            let mut found_index = -1;
            
            // Binary search ที่เขียนเอง
            while left < right {
                let mid = left + (right - left) / 2;
                if starts[mid].0 < end {
                    left = mid + 1;
                } else {
                    right = mid;
                    found_index = starts[mid].1 as i32;
                }
            }
            
            result.push(found_index);
        }
        return result;
    }
}