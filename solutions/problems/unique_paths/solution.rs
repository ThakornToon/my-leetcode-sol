impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let all_step: i64 = (m+n-2) as i64;
        let max: i64 = (m.max(n)-1) as i64;
        let min: i64 = (m.min(n)-1) as i64;
        let mut temp: i64 = 1;
        let mut num: i64 = 1;
        for i in (max+1)..=all_step {
            temp*=i;
            while num<=min && temp%num==0 {
                temp/=num;
                num+=1;
            }
        }
        let ans = temp as i32;
        return ans;
    }
}