impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32 {
        let mut count = 0;
        
        for &x in &arr1 {
            let mut valid = true;
            for &y in &arr2 {
                if (x - y).abs() <= d {
                    valid = false;
                    break;
                }
            }
            if valid {
                count += 1;
            }
        }
        
        count
    
    }
}