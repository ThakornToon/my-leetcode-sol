impl Solution {
    pub fn distribute_candies(candies: i32, num_people: i32) -> Vec<i32> {
        let mut result = vec![0; num_people as usize];
        let mut candies_remaining = candies;
        let mut give = 1;
        let mut i = 0;
        
        while candies_remaining > 0 {
            let current_give = std::cmp::min(give, candies_remaining);
            result[i as usize % num_people as usize] += current_give;
            candies_remaining -= current_give;
            give += 1;
            i += 1;
        }
        
        result
    }
}