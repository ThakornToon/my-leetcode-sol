impl Solution {
    pub fn tiling_rectangle(n: i32, m: i32) -> i32 {
        let (mut n, mut m) = (n as usize, m as usize);
        
        // Special cases
        if n == m { return 1; }
        
        // ทำให้ n เป็นด้านสั้น
        if n > m {
            std::mem::swap(&mut n, &mut m);
        }
        
        // ใช้ Vec<u32> แทน grid 2D
        let mut rows = vec![0u32; n];
        let full_mask = (1u32 << m) - 1;
        let mut result = i32::MAX;
        
        Self::dfs(&mut rows, n, m, 0, full_mask, &mut result);
        result
    }
    
    fn find_empty(rows: &[u32], m: usize, full_mask: u32) -> Option<(usize, usize)> {
        for (i, &row) in rows.iter().enumerate() {
            if row != full_mask {
                // หาคอลัมน์ว่างแรกในแถวนี้
                for j in 0..m {
                    if row & (1u32 << j) == 0 {
                        return Some((i, j));
                    }
                }
            }
        }
        None
    }
    
    fn can_place(rows: &[u32], x: usize, y: usize, size: usize) -> bool {
        let square_mask = ((1u32 << size) - 1) << y;
        
        for i in 0..size {
            if rows[x + i] & square_mask != 0 {
                return false;
            }
        }
        true
    }
    
    fn place_square(rows: &mut [u32], x: usize, y: usize, size: usize, place: bool) {
        let square_mask = ((1u32 << size) - 1) << y;
        
        if place {
            for i in 0..size {
                rows[x + i] |= square_mask;
            }
        } else {
            let clear_mask = !square_mask;
            for i in 0..size {
                rows[x + i] &= clear_mask;
            }
        }
    }
    
    fn dfs(rows: &mut Vec<u32>, n: usize, m: usize, count: i32, full_mask: u32, result: &mut i32) {
        // Pruning
        if count >= *result {
            return;
        }
        
        if let Some((x, y)) = Self::find_empty(rows, m, full_mask) {
            // หาขนาดสูงสุด
            let mut max_size = (n - x).min(m - y);
            
            // ปรับ max_size โดยตรวจสอบแถวล่าง
            for size in 1..=max_size {
                let mask = ((1u32 << size) - 1) << y;
                if rows[x + size - 1] & mask != 0 {
                    max_size = size - 1;
                    break;
                }
            }
            
            // ลองจากใหญ่ไปเล็ก
            for size in (1..=max_size).rev() {
                if Self::can_place(rows, x, y, size) {
                    Self::place_square(rows, x, y, size, true);
                    Self::dfs(rows, n, m, count + 1, full_mask, result);
                    Self::place_square(rows, x, y, size, false);  // backtrack
                }
            }
        } else {
            // ปูหมดแล้ว
            *result = (*result).min(count);
        }
    }
}