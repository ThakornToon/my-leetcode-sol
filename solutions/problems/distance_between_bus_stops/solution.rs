impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let n = distance.len();
        let start = start as usize;
        let destination = destination as usize;
        
        // คำนวณทั้งสองทิศทาง
        let mut clockwise = 0;
        let mut i = start;
        while i != destination {
            clockwise += distance[i];
            i = (i + 1) % n;
        }
        
        let total: i32 = distance.iter().sum();
        let counterclockwise = total - clockwise;
        
        clockwise.min(counterclockwise)
    }
}