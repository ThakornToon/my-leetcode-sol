impl Solution {
    pub fn find_longest_chain(pairs: Vec<Vec<i32>>) -> i32 {
        // เรียงลำดับตาม b (สิ้นสุด)
        let mut pairs = pairs;
        pairs.sort_by(|a, b| a[1].cmp(&b[1]));
        
        let mut count = 1;
        let mut current_end = pairs[0][1];
        
        for i in 1..pairs.len() {
            if pairs[i][0] > current_end {
                count += 1;
                current_end = pairs[i][1];
            }
        }
        
        count
    }
}