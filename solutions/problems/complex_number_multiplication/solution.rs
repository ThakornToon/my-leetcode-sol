impl Solution {
    pub fn complex_number_multiply(num1: String, num2: String) -> String {
        // Parse first complex number
        let parts1: Vec<&str> = num1.split('+').collect();
        let a: i32 = parts1[0].parse().unwrap();
        let b: i32 = parts1[1].trim_end_matches('i').parse().unwrap();
        
        // Parse second complex number
        let parts2: Vec<&str> = num2.split('+').collect();
        let c: i32 = parts2[0].parse().unwrap();
        let d: i32 = parts2[1].trim_end_matches('i').parse().unwrap();
        
        // Calculate result
        let real = a * c - b * d;
        let imag = a * d + b * c;
        
        format!("{}+{}i", real, imag)
    }
}