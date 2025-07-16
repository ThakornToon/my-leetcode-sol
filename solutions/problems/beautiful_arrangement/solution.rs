impl Solution {
    pub fn count_arrangement(n: i32) -> i32 {
        let mut visited = vec![false; (n + 1) as usize];
        let mut count = 0;
        Solution::backtrack(n, 1, &mut visited, &mut count);
        count
    }
    
    fn backtrack(n: i32, pos: i32, visited: &mut Vec<bool>, count: &mut i32) {
        if pos > n {
            *count += 1;
            return;
        }
        
        for num in 1..=n {
            if !visited[num as usize] && (num % pos == 0 || pos % num == 0) {
                visited[num as usize] = true;
                Solution::backtrack(n, pos + 1, visited, count);
                visited[num as usize] = false;
            }
        }
    }
}