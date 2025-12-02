int maxDistToClosest(int* seats, int seatsSize) {
    int n = seatsSize;
    int maxDist = 0;
    int lastPerson = -1;  // ตำแหน่งคนนั่งล่าสุด
    
    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            if (lastPerson == -1) {
                // คนนั่งคนแรก → ระยะทางจากจุดเริ่มต้น
                maxDist = i;
            } else {
                // คนนั่งระหว่างทาง → ระยะทางที่จุดกึ่งกลาง
                int dist = (i - lastPerson) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                }
            }
            lastPerson = i;
        }
    }
    
    // ตรวจสอบช่องว่างทางขวาสุด
    if (lastPerson != n-1) {
        int dist = n - 1 - lastPerson;
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    
    return maxDist;
}