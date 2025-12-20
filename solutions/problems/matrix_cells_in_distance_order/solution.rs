impl Solution {
    pub fn all_cells_dist_order(rows: i32, cols: i32, r_center: i32, c_center: i32) -> Vec<Vec<i32>> {
        let mut cells: Vec<Vec<i32>> = Vec::new();
        
        // Generate all cells with distances
        for r in 0..rows {
            for c in 0..cols {
                let dist = (r - r_center).abs() + (c - c_center).abs();
                cells.push(vec![r, c, dist]);
            }
        }
        
        // Sort by distance
        cells.sort_by_key(|cell| cell[2]);
        
        // Remove distance and keep only coordinates
        cells.into_iter()
            .map(|cell| vec![cell[0], cell[1]])
            .collect()
    }
}