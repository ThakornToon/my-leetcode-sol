impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        let mut sorted = deck.clone();
        sorted.sort_unstable_by(|a, b| b.cmp(a)); // เรียงจากมากไปน้อย
        
        use std::collections::VecDeque;
        let mut dq = VecDeque::new();
        
        for card in sorted {
            if !dq.is_empty() {
                let back = dq.pop_back().unwrap();
                dq.push_front(back);
            }
            dq.push_front(card);
        }
        
        dq.into_iter().collect()
    }
}