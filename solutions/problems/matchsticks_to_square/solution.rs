impl Solution {
    fn backtrack(matchsticks: &[i32], index: usize, sides: &mut [i32; 4], target: i32) -> bool {
        if index == matchsticks.len() {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }
        
        for i in 0..4 {
            if sides[i] + matchsticks[index] > target {
                continue;
            }
            if i > 0 && sides[i] == sides[i-1] {
                continue;
            }
            
            sides[i] += matchsticks[index];
            if Self::backtrack(matchsticks, index + 1, sides, target) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        
        false
    }

    pub fn makesquare(matchsticks: Vec<i32>) -> bool {
        let total: i32 = matchsticks.iter().sum();
        if total % 4 != 0 {
            return false;
        }
        
        let target = total / 4;
        let mut matchsticks = matchsticks;
        matchsticks.sort_unstable_by(|a, b| b.cmp(a)); // มากไปน้อย
        let mut sides = [0; 4];
        
        Self::backtrack(&matchsticks, 0, &mut sides, target)
    }
}