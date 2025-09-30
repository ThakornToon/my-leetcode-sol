char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    
    // ใช้ array ธรรมดาเก็บตำแหน่ง
    int radiant[10000], dire[10000];
    int rad_count = 0, dir_count = 0;
    
    // แยกเก็บตำแหน่งเริ่มต้น
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant[rad_count++] = i;
        } else {
            dire[dir_count++] = i;
        }
    }
    
    // จำลองการโหวต
    int rad_idx = 0, dir_idx = 0;
    while (rad_idx < rad_count && dir_idx < dir_count) {
        // เปรียบเทียบตำแหน่ง
        if (radiant[rad_idx] < dire[dir_idx]) {
            // R โหวตก่อน → ห้าม D
            radiant[rad_count++] = radiant[rad_idx] + n;  // R โหวตอีกครั้งในรอบหน้า
        } else {
            // D โหวตก่อน → ห้าม R  
            dire[dir_count++] = dire[dir_idx] + n;  // D โหวตอีกครั้งในรอบหน้า
        }
        rad_idx++;
        dir_idx++;
    }
    
    return (rad_idx < rad_count) ? "Radiant" : "Dire";
}