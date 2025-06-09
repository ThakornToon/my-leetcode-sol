impl Solution {
    fn backtrack(k: i32, n: i32, res: &mut Vec<Vec<i32>>, store: &mut Vec<i32>, start: i32) {
        if k == 0 {
            if n!=0 {
                return;
            }
            res.push(store.clone());
            return;
        }
        for i in start..=9 {
            if n - i < 0 {
                return;
            }
            store.push(i);
            Self::backtrack(k-1, n-i, res, store, i+1);
            store.pop();
        }
    }
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        if k * (k + 1) / 2 > n {
            return vec![];
        }
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut store: Vec<i32> = Vec::new();
        Self::backtrack(k, n, &mut res, &mut store, 1);
        return res;
    }
}