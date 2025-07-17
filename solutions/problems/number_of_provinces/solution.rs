impl Solution {
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        let n = is_connected.len();
        let mut visited = vec![false; n];
        let mut provinces = 0;
        
        fn dfs(city: usize, is_connected: &Vec<Vec<i32>>, visited: &mut Vec<bool>) {
            visited[city] = true;
            for neighbor in 0..is_connected.len() {
                if is_connected[city][neighbor] == 1 && !visited[neighbor] {
                    dfs(neighbor, is_connected, visited);
                }
            }
        }
        
        for i in 0..n {
            if !visited[i] {
                dfs(i, &is_connected, &mut visited);
                provinces += 1;
            }
        }
        
        provinces
    }
}