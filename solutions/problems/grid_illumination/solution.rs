use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn grid_illumination(n: i32, lamps: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as i64;
        let mut rows: HashMap<i32, i32> = HashMap::new();
        let mut cols: HashMap<i32, i32> = HashMap::new();
        let mut diag1: HashMap<i32, i32> = HashMap::new(); // row - col
        let mut diag2: HashMap<i32, i32> = HashMap::new(); // row + col
        let mut lamp_set: HashSet<i64> = HashSet::new();
        
        // Encode position to i64
        let encode = |r: i32, c: i32| -> i64 {
            (r as i64) * n + (c as i64)
        };
        
        // Add lamps
        for lamp in &lamps {
            let r = lamp[0];
            let c = lamp[1];
            let key = encode(r, c);
            
            if !lamp_set.contains(&key) {
                lamp_set.insert(key);
                *rows.entry(r).or_insert(0) += 1;
                *cols.entry(c).or_insert(0) += 1;
                *diag1.entry(r - c).or_insert(0) += 1;
                *diag2.entry(r + c).or_insert(0) += 1;
            }
        }
        
        // Directions for 3x3 block
        let dirs = [
            (0, 0), (0, 1), (0, -1),
            (1, 0), (1, 1), (1, -1),
            (-1, 0), (-1, 1), (-1, -1)
        ];
        
        let mut result = Vec::new();
        
        // Process queries
        for query in &queries {
            let r = query[0];
            let c = query[1];
            
            // Check illumination
            let illuminated = rows.get(&r).unwrap_or(&0) > &0 ||
                             cols.get(&c).unwrap_or(&0) > &0 ||
                             diag1.get(&(r - c)).unwrap_or(&0) > &0 ||
                             diag2.get(&(r + c)).unwrap_or(&0) > &0;
            
            result.push(if illuminated { 1 } else { 0 });
            
            // Turn off lamps in 3x3 block
            for dir in dirs.iter() {
                let nr = r + dir.0;
                let nc = c + dir.1;
                
                if nr >= 0 && nr < n as i32 && nc >= 0 && nc < n as i32 {
                    let key = encode(nr, nc);
                    
                    if lamp_set.contains(&key) {
                        lamp_set.remove(&key);
                        *rows.entry(nr).or_insert(0) -= 1;
                        *cols.entry(nc).or_insert(0) -= 1;
                        *diag1.entry(nr - nc).or_insert(0) -= 1;
                        *diag2.entry(nr + nc).or_insert(0) -= 1;
                    }
                }
            }
        }
        
        result

    }
}