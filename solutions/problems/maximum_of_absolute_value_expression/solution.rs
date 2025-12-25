/*
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
|x| = max(x, -x) จะมีทั้งหมด 8 กรณ๊
1. (+1, +1, +1): (A+B+i) - (A+B+j)
2. (+1, +1, -1): (A+B-i) - (A+B-j)
3. (+1, -1, +1): (A-B+i) - (A-B+j)
4. (+1, -1, -1): (A-B-i) - (A-B-j)
--------------------------------------
5. (-1, +1, +1): (-A+B+i) - (-A+B+j)
6. (-1, +1, -1): (-A+B-i) - (-A+B-j)
7. (-1, -1, +1): (-A-B+i) - (-A-B+j)
8. (-1, -1, -1): (-A-B-i) - (-A-B-j)
สังเกตว่าถ้าแบ่งแบบนี้เครื่องหมายหน้า (A1, B1, i) จะเหมือนกับ (A2, B2, j)
และสามารถสลับ i, j ในการคิดเพื่อให้ได้ค่าดีที่สุดในแต่ละกรณีได้

ถ้าเราต้องการหาค่า max ของ |X| + |Y| + |Z| มันเท่ากับหา max ของผลต่างระหว่าง (±X ± Y ± Z) และ max((±a ± b ± c) for i,j) = max(max(±arr1[i] ± arr2[i] ± i) - min(±arr1[j] ± arr2[j] ± j))
จะได้กรณีที่ดีที่สุดเมื่อกรณีนั้นเราใส่เครื่องหมายแทนค่าสมบูรณ์ถูกต้อง
*/

impl Solution {
    pub fn max_abs_val_expr(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
        let n = arr1.len();
        
        // สร้าง array สำหรับเก็บค่า max/min ของทั้ง 8 กรณี
        let mut max_vals = [i32::MIN; 8];
        let mut min_vals = [i32::MAX; 8];
        
        for i in 0..n {
            let i32_i = i as i32;
            let a = arr1[i];
            let b = arr2[i];
            
            // คำนวณค่าทั้ง 8 กรณีสำหรับ index i
            let vals = [
                // S1: +a +b +i
                a + b + i32_i,
                // S2: +a +b -i
                a + b - i32_i,
                // S3: +a -b +i
                a - b + i32_i,
                // S4: +a -b -i
                a - b - i32_i,
                // S5: -a +b +i
                -a + b + i32_i,
                // S6: -a +b -i
                -a + b - i32_i,
                // S7: -a -b +i
                -a - b + i32_i,
                // S8: -a -b -i
                -a - b - i32_i,
            ];
            
            // อัปเดตค่า max และ min สำหรับแต่ละกรณี
            for k in 0..8 {
                if vals[k] > max_vals[k] {
                    max_vals[k] = vals[k];
                }
                if vals[k] < min_vals[k] {
                    min_vals[k] = vals[k];
                }
            }
        }
        
        // หาค่าสูงสุดจากผลต่าง max - min ของทุกกรณี
        let mut result = 0;
        for k in 0..8 {
            let diff = max_vals[k] - min_vals[k];
            if diff > result {
                result = diff;
            }
        }
        
        result
    }
}