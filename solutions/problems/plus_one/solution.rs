impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let n = digits.len();
        let mut d = digits;
        for x in (0..n).rev(){
            if d[x]<9 {
                d[x]+=1;
                let d = d;
                return d;
            }
            d[x]=0;
       }
       let mut d = vec![0; n+1];
       d[0]=1;
       d
    }
}