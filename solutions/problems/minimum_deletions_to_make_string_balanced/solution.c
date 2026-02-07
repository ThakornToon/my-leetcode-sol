int minimumDeletions(char* s) {
    int n = strlen(s);
    
    // นับจำนวน 'a' ทั้งหมด
    int total_a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') total_a++;
    }
    
    int b_left = 0;  // จำนวน 'b' ทางซ้ายของจุดแบ่ง
    int a_right = total_a;  // จำนวน 'a' ทางขวาของจุดแบ่ง
    
    int min_deletions = n;  // เริ่มต้นด้วยค่าสูงสุด
    
    // พิจารณาจุดแบ่งก่อนตัวแรก (ลบ 'a' ทั้งหมด)
    min_deletions = total_a;
    
    // พิจารณาจุดแบ่งแต่ละตำแหน่ง
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a_right--;
        } else { // 'b'
            b_left++;
        }
        
        // deletions = ลบ 'b' ทางซ้าย + ลบ 'a' ทางขวา
        int deletions = b_left + a_right;
        if (deletions < min_deletions) {
            min_deletions = deletions;
        }
    }
    
    // พิจารณาจุดแบ่งหลังตัวสุดท้าย (ลบ 'b' ทั้งหมด)
    if (n - total_a < min_deletions) {
        min_deletions = n - total_a;
    }
    
    return min_deletions;
}