/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * struct CustomFunction;
 * impl CustomFunction {
 *    pub fn f(x:i32,y:i32)->i32{}
 * }
 */

impl Solution {
    pub fn find_solution(customfunction: &CustomFunction, z: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut x = 1;
        let mut y = 1000;
        
        while x <= 1000 && y >= 1 {
            let val = customfunction.f(x, y);
            
            match val.cmp(&z) {
                std::cmp::Ordering::Equal => {
                    result.push(vec![x, y]);
                    x += 1;
                    y -= 1;
                }
                std::cmp::Ordering::Less => {
                    // ค่าน้อยไป → ต้องเพิ่มค่า → เพิ่ม x
                    x += 1;
                }
                std::cmp::Ordering::Greater => {
                    // มากไป → ต้องลดค่า → ลด y
                    y -= 1;
                }
            }
        }
        
        result
    }
}