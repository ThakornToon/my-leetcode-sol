impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut v:Vec<i32> = vec![1;((n+1) as usize)];
        let mut i:usize = 1;
        while (i as i32) < n{
            i+=1;
            v[i]=v[i-1]+v[i-2];
        }
        return v[i];
    }
}