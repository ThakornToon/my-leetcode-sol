pub enum Direction {
    Left,
    Right,
    Up,
    Down,
}

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut top: usize = 0;
        let mut left: usize = 0;
        let mut bottom: usize = (matrix.len() - 1);
        let mut right: usize = (matrix[0].len() - 1);
        
        let mut soln = vec![];
        let mut dir: Direction = Direction::Right;

        while (soln.len() < matrix.len() * matrix[0].len()) {
            match dir {
                Direction::Right => {
                    for ri in left..=right {
                        soln.push(matrix[top][ri]);
                    }
                    top += 1;
                    dir = Direction::Down;
                },
                Direction::Down => {
                    for bi in top..=bottom {
                        soln.push(matrix[bi][right]);
                    }
                    right -= 1;
                    dir = Direction::Left;
                },
                Direction::Left => {
                    for li in (left..=right).rev() {
                        soln.push(matrix[bottom][li]);
                    }
                    bottom -= 1;
                    dir = Direction::Up;
                },
                Direction::Up => {
                    for bi in (top..=bottom).rev() {
                        soln.push(matrix[bi][left]);
                    }
                    left += 1;
                    dir = Direction::Right;
                }
            }
        }
        return soln;
    }
}