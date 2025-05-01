impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut num: i32 = 0;
        let mut i: i32 = 0;
        let mut carry: i32 = x;
        while carry != 0{
            if let Some(result) = num.checked_mul(10){
                num*=10;
            }
            else{
                return 0;
            }
            i = carry%10;
            if let Some(result) = num.checked_add(i){
                num+=i;
            }
            else{
                return 0;
            }
            carry/=10;
        }
        
        return num;
        
    }
}