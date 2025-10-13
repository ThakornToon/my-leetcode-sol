impl Solution {
    pub fn sliding_puzzle(board: Vec<Vec<i32>>) -> i32 {
        let target = "123450".to_string();
        let mut start = String::new();
        
        // แปลงบอร์ดเป็น string
        for i in 0..2 {
            for j in 0..3 {
                start.push_str(&board[i][j].to_string());
            }
        }
        
        let mut visited = Vec::new();
        let mut queue = std::collections::VecDeque::new();
        
        queue.push_back((start.clone(), 0));
        visited.push(start);
        
        let directions = [(-1, 0), (0, 1), (1, 0), (0, -1)];
        
        while let Some((current, moves)) = queue.pop_front() {
            if current == target {
                return moves;
            }
            
            // หาตำแหน่งช่องว่าง
            let zero_pos = current.find('0').unwrap();
            let row = zero_pos / 3;
            let col = zero_pos % 3;
            
            for (dr, dc) in directions.iter() {
                let new_row = row as i32 + dr;
                let new_col = col as i32 + dc;
                
                if new_row >= 0 && new_row < 2 && new_col >= 0 && new_col < 3 {
                    let new_pos = (new_row * 3 + new_col) as usize;
                    
                    let mut next_state = current.chars().collect::<Vec<char>>();
                    next_state.swap(zero_pos, new_pos);
                    let next_state_str: String = next_state.iter().collect();
                    
                    // ตรวจสอบว่า state นี้ยังไม่เคยเห็น
                    if !visited.contains(&next_state_str) {
                        visited.push(next_state_str.clone());
                        queue.push_back((next_state_str, moves + 1));
                    }
                }
            }
        }
        
        -1
    }
}