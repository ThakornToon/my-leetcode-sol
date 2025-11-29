impl Solution {
    pub fn flip_and_invert_image(image: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut result = image;
        let n = result.len();
        
        for row in result.iter_mut() {
            row.reverse(); // Flip horizontally
            for pixel in row.iter_mut() {
                *pixel = 1 - *pixel; // Invert
            }
        }
        
        result
    }
}