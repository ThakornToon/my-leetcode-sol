/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 *  struct MountainArray;
 *  impl MountainArray {
 *     fn get(index:i32)->i32;
 *     fn length()->i32;
 * };
 */

impl Solution {
    pub fn find_in_mountain_array(target: i32, mountainArr: &MountainArray) -> i32 {
        let n = mountainArr.length();
        
        // 1. หา peak index
        let mut left = 0;
        let mut right = n - 1;
        
        while left < right {
            let mid = left + (right - left) / 2;
            if mountainArr.get(mid) < mountainArr.get(mid + 1) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        let peak = left;
        
        // 2. Binary search ในส่วนซ้าย (เพิ่มขึ้น)
        left = 0;
        right = peak;
        while left <= right {
            let mid = left + (right - left) / 2;
            let val = mountainArr.get(mid);
            
            if val == target {
                return mid;
            } else if val < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 3. Binary search ในส่วนขวา (ลดลง)
        left = peak;
        right = n - 1;
        while left <= right {
            let mid = left + (right - left) / 2;
            let val = mountainArr.get(mid);
            
            if val == target {
                return mid;
            } else if val > target {
                // ลดลง: ถ้า val > target ต้องไปขวา
                left = mid + 1;
            } else {
                // ลดลง: ถ้า val < target ต้องไปซ้าย
                right = mid - 1;
            }
        }
        
        -1
    }
}