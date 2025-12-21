impl Solution {
    pub fn prev_perm_opt1(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        let n = arr.len();

        // หาตำแหน่งแรกที่ arr[i] > arr[i+1] เพื่อเปลี่ยน ไล่จากทางขวา 
        // 123 -> สลับไม่ได้, 221 -> 212
        let mut i = n as i32 - 2;
        while i >= 0 && arr[i as usize] <= arr[(i + 1) as usize] {
            i -= 1;
        }
        
        // ถ้าไม่เจอถือว่าเป้นค่าน้อยสุดแล้ว
        if i < 0 {
            return arr;
        }
        
        // มองทางขวาหาค่าน้อยกว่าที่มากที่สุดมาสลับ
        let i = i as usize;
        let mut max_index = i + 1;
        let mut max_val = arr[max_index];
        
        for k in i + 2..n {
            if arr[k] < arr[i] && arr[k] > max_val {
                max_val = arr[k];
                max_index = k;
            }
        }
        
        // สลับ arr[i] กับ arr[maxIndex]
        arr.swap(i, max_index);
        
        return arr;
    }
}