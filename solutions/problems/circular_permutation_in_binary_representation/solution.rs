impl Solution {
    pub fn circular_permutation(n: i32, start: i32) -> Vec<i32> {
        let size = 1usize << n;
        let mut visited = vec![false; size];
        let mut result = Vec::with_capacity(size);
        
        result.push(start);
        visited[start as usize] = true;
        
        Self::dfs_backtrack(n, start, &mut result, &mut visited);
        
        result
    }

    fn dfs_backtrack(n: i32, current: i32, result: &mut Vec<i32>, visited: &mut Vec<bool>) -> bool {
        let size = 1 << n;
        
        // ถ้าได้ครบทุกตัวแล้ว
        if result.len() == size {
            // ตรวจสอบ circular condition
            let first = result[0];
            let last = *result.last().unwrap();
            let diff = first ^ last;
            return diff.count_ones() == 1;
        }
        
        // ลองเปลี่ยนแต่ละบิต
        for i in 0..n {
            let next = current ^ (1 << i);
            let idx = next as usize;
            
            if !visited[idx] {
                visited[idx] = true;
                result.push(next);
                
                if Self::dfs_backtrack(n, next, result, visited) {
                    return true;
                }
                
                // backtrack
                result.pop();
                visited[idx] = false;
            }
        }
        
        false
    }
}