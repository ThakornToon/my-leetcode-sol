bool escapeGhosts(int** ghosts, int ghostsSize, int* ghostsColSize, int* target, int targetSize) {
    // ระยะทางจากผู้เล่นถึงเป้าหมาย
    int player_dist = abs(target[0]) + abs(target[1]);
    
    for (int i = 0; i < ghostsSize; i++) {
        // ระยะทางจากผีถึงเป้าหมาย
        int ghost_dist = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
        
        // ถ้าผีไปถึงเป้าหมายก่อนหรือพร้อมกับผู้เล่น
        if (ghost_dist <= player_dist) {
            return false;
        }
    }
    
    return true;
}