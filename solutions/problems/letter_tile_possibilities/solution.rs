impl Solution {
    fn backtrack(count: &mut i32, freq: &mut [i32; 26]) {
        for i in 0..26 {
            if freq[i] > 0 {
                // Use this character
                *count += 1;
                freq[i] -= 1;
                
                // Recurse
                Self::backtrack(count, freq);
                
                // Backtrack
                freq[i] += 1;
            }
        }
    }
    
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut freq = [0; 26];
        for c in tiles.chars() {
            freq[(c as u8 - b'A') as usize] += 1;
        }
        
        let mut count = 0;
        Self::backtrack(&mut count, &mut freq);
        count
    }
}