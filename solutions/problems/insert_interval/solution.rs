impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort();
        let mut result = vec![];
        let mut new_interval = new_interval;
        for interval in intervals {
            if new_interval[0]>interval[1] {
                result.push(interval);
            } 
            else if new_interval[1]<interval[0] {
                result.push(new_interval);
                new_interval = interval;
            }
            else {
                new_interval[1] = new_interval[1].max(interval[1]);
                new_interval[0] = new_interval[0].min(interval[0]);
            }
        }
        result.push(new_interval);
        result
    }
}