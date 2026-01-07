use std::collections::HashSet;

impl Solution {
    pub fn queens_attackthe_king(queens: Vec<Vec<i32>>, king: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        
        // เก็บตำแหน่ง queens ใน HashSet
        let queen_set: HashSet<(i32, i32)> = queens
            .iter()
            .map(|q| (q[0], q[1]))
            .collect();
        
        // ทิศทางทั้ง 8
        let directions = [
            (-1, -1), (-1, 0), (-1, 1),  
            (0, -1),           (0, 1),   
            (1, -1),  (1, 0),  (1, 1)  
        ];
        
        let (king_row, king_col) = (king[0], king[1]);
        
        // สำรวจแต่ละทิศทาง
        for (dr, dc) in directions.iter() {
            let mut row: i32 = king_row + dr;
            let mut col: i32 = king_col + dc;
            
            // เดินไปตามทิศทางจนกว่าจะออกนอกกระดาน
            while row >= 0 && row < 8 && col >= 0 && col < 8 {
                if queen_set.contains(&(row, col)) {
                    // พบ queen ในทิศทางนี้
                    result.push(vec![row, col]);
                    break;  // หยุดค้นหาในทิศทางนี้
                }
                
                // เดินต่อไปในทิศทางเดิม
                row += dr;
                col += dc;
            }
        }
        
        return result;
    }
}