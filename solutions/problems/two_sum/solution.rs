impl Solution {
    pub fn two_sum(nums: Vec<i32>, target:i32) -> Vec<i32> {
        let mut i:usize = 0;
        let mut i2:usize = 0;
        let mut v:Vec<i32> = Vec::new();
        while i < nums.len(){ //ใช้ len ได้ usize
            i2  = i+1;
            while i2 < nums.len(){
                //index ต้องเป็น usize
                if nums[i]+nums[i2] == target{
                    v.push(i as i32);
                    v.push(i2 as i32);
                    return v;
                } 
                i2+=1;
            }
            i+=1;
        }
        return v;

    }
}