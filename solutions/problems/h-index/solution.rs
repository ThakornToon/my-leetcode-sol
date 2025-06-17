impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut cits = citations;
        cits.sort();
        let mut current_cit_number = 0;

        for &c in cits.iter().rev() {
            if c > current_cit_number {
                current_cit_number += 1;
            } else {
                break;
            }
        }
        
        current_cit_number
    }
}