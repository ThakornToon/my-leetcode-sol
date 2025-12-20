impl Solution {
    pub fn two_city_sched_cost(costs: Vec<Vec<i32>>) -> i32 {
        let mut costs = costs;
        
        // Sort by (aCost - bCost)
        costs.sort_by_key(|c| c[0] - c[1]);
        
        let n = costs.len() / 2;
        let mut total = 0;
        
        // First n to city A
        for i in 0..n {
            total += costs[i][0];
        }
        
        // Last n to city B
        for i in n..2*n {
            total += costs[i][1];
        }
        
        total
    }
}