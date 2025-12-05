use std::collections::HashSet;

impl Solution {
    pub fn robot_sim(commands: Vec<i32>, obstacles: Vec<Vec<i32>>) -> i32 {
        // ทิศทาง: north, east, south, west
        let directions: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        
        // เก็บอุปสรรคใน HashSet
        let obstacle_set: HashSet<(i32, i32)> = 
            obstacles.into_iter().map(|v| (v[0], v[1])).collect();
        
        let mut x = 0;
        let mut y = 0;
        let mut dir = 0; // เริ่มทิศเหนือ
        let mut max_distance = 0;
        
        for &cmd in &commands {
            match cmd {
                -2 => dir = (dir + 3) % 4, // หันซ้าย
                -1 => dir = (dir + 1) % 4, // หันขวา
                steps => {
                    for _ in 0..steps {
                        let next_x = x + directions[dir].0;
                        let next_y = y + directions[dir].1;
                        
                        // ตรวจสอบอุปสรรค
                        if obstacle_set.contains(&(next_x, next_y)) {
                            break;
                        }
                        
                        x = next_x;
                        y = next_y;
                        
                        // อัพเดตระยะทางสูงสุด
                        max_distance = max_distance.max(x * x + y * y);
                    }
                }
            }
        }
        
        max_distance
    }
}