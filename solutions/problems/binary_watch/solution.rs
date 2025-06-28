impl Solution {
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut times = Vec::new();
        
        for h in 0i32..12 {
            for m in 0i32..60 {
                if (h.count_ones() + m.count_ones()) as i32 == turned_on {
                    times.push(format!("{}:{:02}", h, m));
                }
            }
        }
        
        times
    }
}