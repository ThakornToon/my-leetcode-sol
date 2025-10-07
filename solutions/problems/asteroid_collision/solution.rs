impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        
        for &asteroid in &asteroids {
            // For positive asteroids or when stack is empty, just push
            if stack.is_empty() || asteroid > 0 {
                stack.push(asteroid);
                continue;
            }
            
            // Handle negative asteroid (moving left)
            let mut destroyed = false;
            while let Some(&last) = stack.last() {
                if last < 0 {
                    break; // Same direction, no collision
                }
                
                if last < -asteroid {
                    // Current stack asteroid is smaller, pop it
                    stack.pop();
                } else if last == -asteroid {
                    // Both asteroids destroy each other
                    stack.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid is smaller, destroy it
                    destroyed = true;
                    break;
                }
            }
            
            // If negative asteroid survived all collisions, push it
            if !destroyed {
                stack.push(asteroid);
            }
        }
        
        stack
    }
}