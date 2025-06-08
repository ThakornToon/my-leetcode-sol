impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = numbers.len() - 1;
        let mut ans: Vec<i32> = vec![-1, -1];

        while left < right {
            let total = numbers[left] + numbers[right];

            if total == target {
                ans[0] = (left + 1) as i32;
                ans[1] = (right + 1) as i32;
                return ans;
            } else if total > target {
                right-=1;
            } else {
                left+=1;
            }
        }
        return ans;
    }
}