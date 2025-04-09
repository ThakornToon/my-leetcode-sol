impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut v: Vec<i32> = Vec::new();
        let mut sum: i32 = 0;
        let mut i: usize = 0;
        for ch in s.chars(){
            let x: i32 = match ch{
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => 0,
            };
            v.push(x);
//            println!("x={x}");
        }
        v.push(0);
        let lo = v.len();
        while i < lo-1{
            if v[i]>=v[i+1]{
                sum=sum+v[i];
            }
            else{
                sum=sum-v[i];
            }
//            let o:i32 = v[i]; 
//            println!("v[i]={o} ,sum={sum}");
            i+=1;
        }
        return sum;
    }
}