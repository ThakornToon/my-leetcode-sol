impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut totalGas = 0;
        let mut currentGas = 0;
        let mut start = 0;

        for i in 0..gas.len() {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];
            if currentGas < 0 {
                start = i + 1;
                currentGas = 0;
            }
        }
        if totalGas < 0 {
            -1
        } else {
            start as i32
        }
    }
}