impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut l: usize = 0;
        let mut r: usize = letters.len();
        let mut m: usize = 0;
        while l < r {
            m = l + (r-l)/2;
            if letters[m] <= target {
                l = m + 1;
            } else {
                r = m;
            }
        }
        letters[l % letters.len()] 
    }
}