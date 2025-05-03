impl Solution {
    fn backtrack(result: &mut Vec<Vec<i32>>, store: &mut Vec<i32>, candidates: &Vec<i32>, target: i32, start: usize){
        if target==0{
            result.push(store.clone());
            return;
        }
        for i in start..candidates.len(){
            if target-candidates[i] >= 0{
                store.push(candidates[i].clone());
                Self::backtrack(result, store, candidates, target-candidates[i], i);
                store.pop();
            }
        }
    }

    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut store = Vec::new();
        Self::backtrack(&mut result, &mut store, &candidates, target, 0);
        return result;
    }
}