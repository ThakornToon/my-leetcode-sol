int calculateDistance(int* p1, int* p2) {
    int dx = p1[0] - p2[0];
    int dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    // สร้าง array ของ points
    int* points[4] = {p1, p2, p3, p4};
    int dists[6];
    int distIndex = 0;
    
    // คำนวณระยะทางทั้งหมด 6 ระยะ
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int dist = calculateDistance(points[i], points[j]);
            if (dist == 0) return false; // จุดซ้ำ
            dists[distIndex++] = dist;
        }
    }
    
    // เรียงลำดับระยะทาง
    qsort(dists, 6, sizeof(int), compare);
    
    // ตรวจสอบคุณสมบัติของสี่เหลี่ยมจัตุรัส
    return (dists[0] == dists[1] && 
            dists[1] == dists[2] && 
            dists[2] == dists[3] && 
            dists[4] == dists[5] && 
            dists[0] * 2 == dists[4]);
}