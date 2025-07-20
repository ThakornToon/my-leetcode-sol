impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let len1 = s1.len();
        let len2 = s2.len();
        
        if len1 > len2 {
            return false;
        }
        
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();
        
        let mut count1 = [0; 26];
        let mut count2 = [0; 26];
        
        for i in 0..len1 {
            count1[(s1[i] - b'a') as usize] += 1;
            count2[(s2[i] - b'a') as usize] += 1;
        }
        
        let mut matches = 0;
        for i in 0..26 {
            if count1[i] == count2[i] {
                matches += 1;
            }
        }
        
        for i in len1..len2 {
            if matches == 26 {
                return true;
            }
            
            let left = (s2[i - len1] - b'a') as usize;
            count2[left] -= 1;
            if count2[left] == count1[left] {
                matches += 1;
            } else if count2[left] == count1[left] - 1 {
                matches -= 1;
            }
            
            let right = (s2[i] - b'a') as usize;
            count2[right] += 1;
            if count2[right] == count1[right] {
                matches += 1;
            } else if count2[right] == count1[right] + 1 {
                matches -= 1;
            }
        }
        
        matches == 26
    }
}