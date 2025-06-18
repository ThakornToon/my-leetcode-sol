impl Solution {
    pub fn is_self_crossing(distance: Vec<i32>) -> bool {
        for  i in 3..distance.len() {
            // กรณี 1: เส้นที่ i ตัดกับเส้นที่ i-3
            if (distance[i] >= distance[i-2] && distance[i-1] <= distance[i-3]) {
                return true;
            }
            
            // กรณี 2: เส้นที่ i ตัดกับเส้นที่ i-4 (เมื่อ i >= 4)
            if (i >= 4 && distance[i-1] == distance[i-3] && distance[i] + distance[i-4] >= distance[i-2]) {
                return true;
            }
            
            // กรณี 3: เส้นที่ i ตัดกับเส้นที่ i-5 (เมื่อ i >= 5)
            if (i >= 5 && distance[i-2] >= distance[i-4] && 
                distance[i-3] >= distance[i-1] && 
                distance[i-1] + distance[i-5] >= distance[i-3] && 
                distance[i] + distance[i-4] >= distance[i-2]) {
                return true;
            }
        }
        return false;
    }
}