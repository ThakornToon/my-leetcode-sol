impl Solution {
    pub fn rank_teams(votes: Vec<String>) -> String {
        use std::collections::HashMap;
        
        if votes.is_empty() {
            return String::new();
        }
        
        let num_teams = votes[0].len();
        let mut scores: HashMap<char, Vec<i32>> = HashMap::new();
        
        for c in votes[0].chars() {
            scores.insert(c, vec![0; num_teams]);
        }
        
        for vote in &votes {
            for (i, c) in vote.chars().enumerate() {
                scores.get_mut(&c).unwrap()[i] += 1;
            }
        }
        
        let mut teams: Vec<char> = votes[0].chars().collect();
        teams.sort_by(|a, b| {
            for i in 0..num_teams {
                if scores[a][i] != scores[b][i] {
                    return scores[b][i].cmp(&scores[a][i]);
                }
            }
            a.cmp(b)
        });
        
        teams.into_iter().collect()
    }
}