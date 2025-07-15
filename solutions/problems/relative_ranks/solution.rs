impl Solution {
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let len = score.len();
        let mut players: Vec<(usize, i32)> = score.into_iter().enumerate().map(|(i, s)| (i, s)).collect();
        players.sort_by(|a, b| b.1.cmp(&a.1));
        
        let mut result = vec![String::new(); len];
        for (rank, &(idx, _)) in players.iter().enumerate() {
            result[idx] = match rank {
                0 => "Gold Medal".to_string(),
                1 => "Silver Medal".to_string(),
                2 => "Bronze Medal".to_string(),
                _ => (rank + 1).to_string(),
            };
        }
        
        result
    }
}