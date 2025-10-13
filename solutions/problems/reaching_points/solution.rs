impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 { a } else { Self::gcd(b, a % b) }
    }

    pub fn reaching_points(sx: i32, sy: i32, tx: i32, ty: i32) -> bool {
        if Self::gcd(sx, sy) != Self::gcd(tx, ty) {
            return false;
        }
        
        let (mut tx, mut ty) = (tx, ty);
        while tx >= sx && ty >= sy {
            if tx == sx && ty == sy {
                return true;
            }
            
            if tx > ty {
                if ty > sy {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if tx > sx {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        false
    }
}