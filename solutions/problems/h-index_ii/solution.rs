impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut l: i32 = 0;
        let mut r: i32 = citations.len() as i32 - 1;
        while l <= r {
            let mid = (l + (r - l) / 2) as usize;
            let count_paper: i32 = (citations.len() - mid) as i32;
            if citations[mid] == count_paper {
                return citations[mid];
            } else if citations[mid] < count_paper {
                l = mid as i32 + 1;
            } else {
                r = mid as i32 - 1;
            }
        }
        return citations.len() as i32 - l;
    }
}