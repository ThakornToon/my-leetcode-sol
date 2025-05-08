impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut v:Vec<i32> = vec![1;3];
        let mut n = n;
        while n>=2{
            v[2]=v[1]+v[0];
            v[0]=v[1];
            v[1]=v[2];
            n-=1;
        }
        return v[2];
    }
}