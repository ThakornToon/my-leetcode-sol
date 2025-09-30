impl Solution {
    pub fn maximum_swap(num: i32) -> i32 {
        let mut s: Vec<char> = num.to_string().chars().collect();
        let n = s.len();
        
        // เก็บ index ของตัวเลขที่ใหญ่ที่สุดจากขวา
        let mut max_right = vec![0; n];
        max_right[n-1] = n-1;
        
        for i in (0..n-1).rev() {
            if s[i] > s[max_right[i+1]] {
                max_right[i] = i;
            } else {
                max_right[i] = max_right[i+1];
            }
        }
        
        // หาตำแหน่งแรกที่ตัวเลขไม่ใช่ค่าสูงสุดจากขวา
        for i in 0..n {
            if s[i] < s[max_right[i]] {
                s.swap(i, max_right[i]);
                break;
            }
        }
        
        s.iter().collect::<String>().parse().unwrap()
    }
}