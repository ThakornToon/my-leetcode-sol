impl Solution {
    pub fn make_array_increasing(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
        let mut arr2 = arr2;
        // เรียงและลบค่าซ้ำ
        arr2.sort_unstable();
        arr2.dedup();
        
        let n = arr1.len();
        let m = arr2.len();
        const INF: i32 = 1_000_000_000;
        
        // keep[i] = min ops เมื่อใช้ arr1[i] (ไม่เปลี่ยน)
        let mut keep = vec![INF; n];
        // change[i][j] = min ops เมื่อเปลี่ยน arr1[i] เป็น arr2[j]
        let mut change = vec![vec![INF; m]; n];
        
        // เริ่มต้น
        keep[0] = 0;
        for j in 0..m {
            change[0][j] = 1;
        }
        
        for i in 1..n {
            // คำนวณ keep[i]
            if arr1[i] > arr1[i - 1] {
                keep[i] = keep[i].min(keep[i - 1]);
            }
            for j in 0..m {
                if arr1[i] > arr2[j] && change[i - 1][j] < INF {
                    keep[i] = keep[i].min(change[i - 1][j]);
                }
            }
            
            // prefix min ของ change[i-1]
            let mut prefix_min = vec![INF; m];
            let mut min_val = INF;
            for j in 0..m {
                min_val = min_val.min(change[i - 1][j]);
                prefix_min[j] = min_val;
            }
            
            // คำนวณ change[i][k]
            for k in 0..m {
                // จาก keep[i-1]
                if arr2[k] > arr1[i - 1] && keep[i - 1] < INF {
                    change[i][k] = change[i][k].min(keep[i - 1] + 1);
                }
                
                // จาก change[i-1][j] ที่ arr2[j] < arr2[k]
                if k > 0 && prefix_min[k - 1] < INF {
                    change[i][k] = change[i][k].min(prefix_min[k - 1] + 1);
                }
            }
        }
        
        let mut result = INF;
        result = result.min(keep[n - 1]);
        for j in 0..m {
            result = result.min(change[n - 1][j]);
        }
        
        if result >= INF { -1 } else { result }
    }
}