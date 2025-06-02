impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let pointsSize = points.len();
        if (pointsSize<=2) {
            return pointsSize as i32;
        }
        let mut maxc = 0;
        for i in 0..pointsSize {
            for j in (i + 1)..pointsSize {
                let x1 = points[i][0];
                let y1 = points[i][1];
                let x2 = points[j][0];
                let y2 = points[j][1];
                let mut count = 2;
                for k in 0..pointsSize {
                    if k != j && k != i {
                        let x = points[k][0];
                        let y = points[k][1];
                        if (y2-y1)*(x-x1) == (x2-x1)*(y-y1) {
                            count+=1;
                        }
                    }
                    else {
                        continue;
                    }
                }
                maxc = maxc.max(count);
            }
            
        }
        return maxc;
    }
}