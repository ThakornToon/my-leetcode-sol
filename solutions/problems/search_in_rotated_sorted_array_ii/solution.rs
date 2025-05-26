impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        let mut left = 0;
        let mut right = nums.len() - 1;
        
        while left <= right {
            let mid = (left + right) / 2;
            
            if nums[mid] == target {
                return true;
            }
            
            if nums[mid] == nums[left] { //ถ้าเท่ากันเราจะไม่สามารถระบุได้ว่าฝั่งซ้ายหรือขวาที่เรียงลำดับกัน โดยปกติจะมีแค่ฝั่งเดียวที่เรียงกัน เลยต้องเลื่อน(เสมือนตัดตัวซ้ำ) 123(1)111ระบุไม่ได้ 111(1)123ระบุไม่ได้ 111(1)231ระบุได้แต่เงื่อนไขด้านล่างnums[left]<=nums[mid]จะทำให้คำตอบผิด 311(1)112ระบุได้ 231(1)111ระบุได้ ต้องมีเพื่อป้องกันทุกกรณี
                left+=1;
                continue;
            }
            
            if nums[left] < nums[mid] {  //ซ้ายเรียงไหม
                if nums[left] <= target && target < nums[mid] {
                    right = mid - 1;
                } 
                else {
                    left = mid + 1;
                }
            } 
            else { //ขวาเรียง
                if nums[mid] < target && target <= nums[right] {
                    left = mid + 1;
                } 
                else {
                    right = mid - 1;
                }
            }
        }
        return false
    }
}