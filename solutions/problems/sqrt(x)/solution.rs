impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut higher = 46340.min(x / 2);
        let mut i = 0;
        while i<=(higher){
            if i*i>x{
                return i-1;
            }
            else if i*i==x{
                return i;
            }
            i+=1
        }
        if 0<x && x<4{
            return 1;
        }
        return higher;
    }
}