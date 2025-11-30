impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let mut chars: Vec<char> = dominoes.chars().collect();
        let n = chars.len();
        let mut i = 0;
        
        while i < n {
            if chars[i] == '.' {
                let mut j = i;
                // Find the segment of '.' between two forces
                while j < n && chars[j] == '.' {
                    j += 1;
                }
                
                let left_force = if i > 0 { chars[i - 1] } else { '.' };
                let right_force = if j < n { chars[j] } else { '.' };
                
                // Apply forces to the segment
                if left_force == 'R' && right_force == 'L' {
                    // Balanced: meet in the middle
                    let mut left = i;
                    let mut right = j - 1;
                    while left < right {
                        chars[left] = 'R';
                        chars[right] = 'L';
                        left += 1;
                        right -= 1;
                    }
                } else if left_force == 'R' {
                    // Push all to right
                    for k in i..j {
                        chars[k] = 'R';
                    }
                } else if right_force == 'L' {
                    // Push all to left  
                    for k in i..j {
                        chars[k] = 'L';
                    }
                }
                // else: no force, remain '.'
                
                i = j;
            } else {
                i += 1;
            }
        }
        
        chars.into_iter().collect()
    }
}