impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort();
        let mut result = vec![];
        let mut cur = vec![];
        for interval in intervals {
            if cur.is_empty() {
                cur = interval;
            } else {
                if cur[1] >= interval[0] {
                    cur[1] = cur[1].max(interval[1])
                } else {
                    result.push(cur);
                    cur = interval;
                }
            }
        }
        result.push(cur);
        result
    }
}