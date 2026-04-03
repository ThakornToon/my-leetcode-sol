impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        let n = arr.len();
        let mut nums_with_index: Vec<(i32, usize)> = arr
            .into_iter()
            .enumerate()
            .map(|(i, num)| (num, i))
            .collect();
        
        nums_with_index.sort_by(|a, b| a.0.cmp(&b.0));
        
        let mut result = vec![0; n];
        let mut rank = 1;
        
        for i in 0..n {
            if i > 0 && nums_with_index[i].0 != nums_with_index[i-1].0 {
                rank += 1;
            }
            result[nums_with_index[i].1] = rank;
        }
        
        result
    }
}