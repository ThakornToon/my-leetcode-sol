impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut total = 1;
        for i in 1..=k {
            total = total * (n - k + i) / i;
        }
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut sub: Vec<i32> = Vec::new();
        for i in 0..=k {
            sub.push(i);
        }
        let k: usize = k as usize;
        let n: usize = n as usize;
        let mut count: usize = k;

    /*
    for example
    12345
    _ _ _ -> 123 -> 124 -> 125 -> (120) -> (130) -> 134 ..... 
i:0 1 2 3 
I didn't use index = 0 to make the code easier to understand.
    */

        loop {
            if sub[1] == 0 {
                break;
            }

            if count >= k {
                res.push(sub[1..].to_vec());
                if sub[count] >= (n - k + count) as i32 {
                    sub[count] = 0;
                } //145->140
                count-=1; //124->12(4)
                continue;
            }

            if sub[count+1] == 0 && sub[count] < (n - k + count) as i32 { //100->230->234
                sub[count]+=1;
                for i in (count+1)..=k {
                    sub[i] = sub[i-1] + 1;
                    count+=1;
                }
            }
            else if sub[count+1] == 0 && sub[count] >= (n - k + count) as i32 { //140->100
                sub[count] = 0;
                count-=1;
            }
            else {//12(4)->125
                count+=1;
                sub[count]+=1;
            }
        } 
        return res;
    }
}