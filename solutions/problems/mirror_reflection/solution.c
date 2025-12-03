int mirrorReflection(int p, int q) {
    int k = 1;
    // หา k ที่น้อยที่สุดที่ k*q หาร p ลงตัว
    while ((k * q) % p != 0) {
        k++;
    }
    
    if (k % 2 == 0) {
        return 2;
    } else {
        int verticalHits = (k * q) / p;
        if (verticalHits % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}