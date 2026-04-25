impl Solution {
    pub fn min_number_of_frogs(croak_of_frogs: String) -> i32 {
        let n = croak_of_frogs.len();
        if n % 5 != 0 {
            return -1;
        }
        
        let mut count = [0; 5];
        let mut active_frogs = 0;
        let mut max_frogs = 0;
        
        for c in croak_of_frogs.chars() {
            match c {
                'c' => {
                    count[0] += 1;
                    active_frogs += 1;
                    max_frogs = max_frogs.max(active_frogs);
                }
                'r' => {
                    if count[0] <= count[1] { return -1; }
                    count[1] += 1;
                }
                'o' => {
                    if count[1] <= count[2] { return -1; }
                    count[2] += 1;
                }
                'a' => {
                    if count[2] <= count[3] { return -1; }
                    count[3] += 1;
                }
                'k' => {
                    if count[3] <= count[4] { return -1; }
                    count[4] += 1;
                    active_frogs -= 1;
                }
                _ => return -1,
            }
        }
        
        if count[0] != count[4] {
            return -1;
        }
        
        max_frogs
    }
}