impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let (s, t) = (s.into_bytes(), t.into_bytes());
        let mut sTable: [usize; 128] = [129; 128];
        let mut tTable: [usize; 128] = [129; 128];
        
        for i in 0..s.len(){
            let s_idx = s[i] as usize;
            let t_idx = t[i] as usize;
            if sTable[s_idx] == 129 {
                sTable[s_idx] = i;
            }
            if tTable[t_idx] == 129 {
                tTable[t_idx] = i;
            }
            if tTable[t_idx] != sTable[s_idx] {
                return false;
            }
        }
        return true;
    }
}