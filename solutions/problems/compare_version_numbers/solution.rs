impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let n1: usize = version1.len();
        let n2: usize = version2.len();
        let version1 = version1.as_bytes();
        let version2 = version2.as_bytes();
        let (mut x1, mut x2) = (0, 0);
        let (mut i, mut j) = (0, 0);
        while i < n1 || j < n2 {
            while i < n1 && version1[i] != b'.' {
                x1 = 10 * x1 + (version1[i] - b'0') as i32;
                i += 1;
            }
            while j < n2 && version2[j] != b'.' {
                x2 = 10 * x2 + (version2[j] - b'0') as i32;
                j += 1;
            }
            if x1 < x2 {
                return -1;
            } 
            else if x1 > x2 {
                return 1;
            }
            x1 = 0;
            x2 = 0;
            i += 1;
            j += 1;
        }
        return 0;
    }
}