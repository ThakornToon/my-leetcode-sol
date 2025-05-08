impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut higher = 46340.min(x / 2);
        let mut i = 0;
        let mut mid = i + (higher - i)/2;
        while i<=higher{
            mid = i + (higher - i)/2;
            if mid*mid>x{
                higher = mid-1;
            }
            else if mid*mid==x{
                return mid;
            }
            else{
                i = mid+1;
            }
        }
        if 0<x && x<4{
            return 1;
        }
        return higher;
    }
}