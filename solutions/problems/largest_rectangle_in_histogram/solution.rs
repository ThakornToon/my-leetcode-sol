impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let size = heights.len();
        let mut area = 0;
        let mut stack: Vec<usize> = vec![];
        for i in 0..size {
            while !stack.is_empty() && heights[i] <= heights[*stack.last().unwrap()] {
                let height = heights[stack.pop().unwrap()];
                let width;
                if stack.is_empty() {
                    width = i as i32;
                }
                else {
                    width = (i - 1 - stack.last().unwrap()) as i32;
                }
                area = area.max(height * width);
            }
            stack.push(i);
        }
        while !stack.is_empty() {
            let height = heights[stack.pop().unwrap()];
            let width;
            if stack.is_empty() {
                width = size as i32;
            }
            else {
                width = (size - 1 - stack.last().unwrap()) as i32;
            }
            area = area.max(height * width);
        }
        return area;
    }
}