impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let l = height.len();
        let mut i: i32 = 0;
        let mut j: i32 = (l-1) as i32;
        let mut vol = 0;
        if l < 2{
            return vol;
        }
        while(i<j){
            if height[i as usize] < height[j as usize]{
                if vol < height[i as usize]*(j-i){
                    vol = height[i as usize]*(j-i);
                }
                i+=1;
            }
            else{
                if vol < height[j as usize]*(j-i){
                    vol = height[j as usize]*(j-i);
                }
                j-=1;
            }
        }
        return vol;
    }
}