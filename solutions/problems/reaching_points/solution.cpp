class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (__gcd(sx, sy) != __gcd(tx, ty)) {
            return false;
        }
        // Now we know GCD matches, use efficient modulo
        while (tx > sx && ty > sy) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        
        // Check final conditions
        if (tx == sx && ty == sy) {
            return true;
        }
        if (tx == sx && ty >= sy) {
            return (ty - sy) % sx == 0;
        }
        if (ty == sy && tx >= sx) {
            return (tx - sx) % sy == 0;
        }
        
        return false;
    }
};