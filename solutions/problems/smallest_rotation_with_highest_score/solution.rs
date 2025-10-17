impl Solution {
    pub fn best_rotation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut diff = vec![0; n + 1];
        
        for i in 0..n {
            let i_val = i as i32;
            let num = nums[i];
            
            if num <= i_val {
                // กรณี 1: nums[i] <= i
                // ได้คะแนนเมื่อ k ∈ [0, i - nums[i]] ∪ [i + 1, n - 1]
                
                diff[0] += 1;  // k=0 ได้คะแนน
                
                let end_first = i - num as usize + 1;
                if end_first < n {
                    diff[end_first] -= 1;  // หมดช่วงแรก
                }
                
                let start_second = i + 1;
                if start_second < n {
                    diff[start_second] += 1;  // เริ่มช่วงสอง
                }
                // ช่วงสองไปจนถึง k = n-1 ไม่ต้องลบ
            } else {
                // กรณี 2: nums[i] > i
                // ได้คะแนนเมื่อ k ∈ [i + 1, n - (nums[i] - i)]
                
                let start = i + 1;
                let end = n - ((num - i_val) as usize);
                
                if start < n {
                    diff[start] += 1;  // เริ่มช่วงได้คะแนน
                }
                
                let end_bound = end + 1;
                if end_bound < n {
                    diff[end_bound] -= 1;  // หมดช่วงได้คะแนน
                }
            }
        }
        
        // คำนวณคะแนนและหาค่า k ที่ดีที่สุด
        let mut max_score = 0;
        let mut best_k = 0;
        let mut current_score = 0;
        
        for k in 0..n {
            current_score += diff[k];
            if current_score > max_score {
                max_score = current_score;
                best_k = k;
            }
        }
        
        best_k as i32
    }
}