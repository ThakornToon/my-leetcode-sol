use std::collections::HashSet;

impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let mut visited = HashSet::new();
        Self::dfs(&arr, start as usize, &mut visited)
    }

    fn dfs(arr: &Vec<i32>, pos: usize, visited: &mut HashSet<usize>) -> bool {
        if pos >= arr.len() || visited.contains(&pos) {
            return false;
        }
        
        if arr[pos] == 0 {
            return true;
        }
        
        visited.insert(pos);
        
        // ไปทางขวา
        if (pos + arr[pos] as usize) < arr.len() {
            if Self::dfs(arr, pos + arr[pos] as usize, visited) {
                return true;
            }
        }
        
        // ไปทางซ้าย
        if pos >= arr[pos] as usize {
            if Self::dfs(arr, pos - arr[pos] as usize, visited) {
                return true;
            }
        }
        
        false
    }

}