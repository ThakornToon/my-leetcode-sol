// Combination function C(n, r)
long long combination(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    long long result = 1;
    r = (r < n - r) ? r : n - r; // เลือก r ที่เล็กกว่า
    
    for (int i = 0; i < r; i++) {
        result = result * (n - i) / (i + 1);
    }
    
    return result;
}

int countVowelStrings(int n) {
    // C(n + 4, 4) 
    // star * : n ตัวอักษร
    // bar | : 4 ส่วนแบ่งตัวอักษรให้ a e i o u
    return (int)combination(n + 4, 4);
}