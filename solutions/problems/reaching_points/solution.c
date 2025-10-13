bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
        if (tx == sx && ty == sy) {
            return true;
        }
        
        if (tx > ty) {
            if (ty > sy) {
                tx %= ty;
            } else {
                // ty == sy, check if we can reach sx
                return (tx - sx) % ty == 0;
            }
        } else {
            if (tx > sx) {
                ty %= tx;
            } else {
                // tx == sx, check if we can reach sy
                return (ty - sy) % tx == 0;
            }
        }
    }
    
    return false;
}