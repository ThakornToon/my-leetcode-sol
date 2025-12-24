impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        // หาตำแหน่งสูงสุด
        let max_location = trips.iter()
            .map(|trip| trip[2])
            .max()
            .unwrap_or(0) as usize;
        
        let mut changes = vec![0; max_location + 1];
        
        for trip in trips {
            let num = trip[0];
            let from = trip[1] as usize;
            let to = trip[2] as usize;
            
            changes[from] += num;
            changes[to] -= num;
        }
        
        let mut current = 0;
        for &change in changes.iter() {
            current += change;
            if current > capacity {
                return false;
            }
        }
        
        true
    }
}