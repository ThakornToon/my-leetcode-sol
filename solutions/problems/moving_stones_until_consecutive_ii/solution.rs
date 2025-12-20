/*
หินอยู่ในช่วง [start, end] ถ้าเราหยิบหินฝั่งใดฝั่งหนึ่งจะต้องหยิบหินนั้นไปวางระหว่างหินช่วงใหม่ [start, new_end] หรือ [new_start, end] 
เช่น
5, 8, 9, 16 เลือก 16 ไปวางในช่องว่างระหว่าง [5,9] ได้ แต่หากต้องการ moves ที่มากที่สุดในครั้งแรกเราต้องเลือกขยับโดยเสียช่องว่างให้น้อยที่สุดจากนั้นในครั้งต่อๆไปให้ผลัดกันขยับหินไปช่องว่างที่ใกล้ที่สุด 5,8,9,16->8,9,10,16 (เสียช่องว่างไปสามช่องเนื่องจากกฎที่บังคับ)->9,10,11,16->10,11,12,16->11,12,13,16->...->13,14,15,16 ในทางกลับกันหากต้องการ moves ที่น้อยที่สุดเราต้องจองพื้นที่ขนาด n ตามจำนวนหินโดยที่มีหินอยู่ในช่วงนั้นมากที่สุด(จะได้ไม่ต้องย้าย) ซึ่งจากนั้นเราแค่นำหินที่ไม่อยู่ในช่วงย้ายมาโดยใช้การ move หนึ่งครั้งต่อหนึ่งก้อน อย่าลืมคิดกรณีที่หินมีอยู่ n-1 ก้อนติดกัน เช่น 8,9,10,16->9,10,12,16->9,10,11,12 
*/
impl Solution {
    pub fn num_moves_stones_ii(stones: Vec<i32>) -> Vec<i32> {
        let mut stones = stones;
        stones.sort_unstable();
        let n = stones.len();
        
        // Calculate maximum moves
        let total_empty = (stones[n-1] - stones[0] + 1) as usize - n;
        let left_gap = (stones[1] - stones[0] - 1) as i32;
        let right_gap = (stones[n-1] - stones[n-2] - 1) as i32;
        let max_moves = total_empty as i32 - left_gap.min(right_gap);
        
        // Calculate minimum moves using sliding window
        let mut min_moves = n as i32;
        let mut j = 0;
        
        for i in 0..n {
            // Expand window
            while j + 1 < n && stones[j + 1] - stones[i] + 1 <= n as i32 {
                j += 1;
            }
            
            let stones_in_window = (j - i + 1) as i32;
            
            // Special case
            if stones_in_window == (n - 1) as i32 && 
               stones[j] - stones[i] + 1 == (n - 1) as i32 {
                min_moves = min_moves.min(2);
            } else {
                min_moves = min_moves.min(n as i32 - stones_in_window);
            }
        }
        
        vec![min_moves, max_moves]
    }
}