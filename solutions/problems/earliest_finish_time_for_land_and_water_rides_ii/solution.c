#define MIN(a, b) ((a) < (b) ? (a) : (b))

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int n = landStartTimeSize;
    int m = waterStartTimeSize;
    
    // หาเวลาจบที่เร็วที่สุดของ land rides (minLandEnd)
    int minLandEnd = INT_MAX;
    for (int i = 0; i < n; i++) {
        int finish = landStartTime[i] + landDuration[i];
        if (finish < minLandEnd) {
            minLandEnd = finish;
        }
    }
    
    // หาเวลาจบที่เร็วที่สุดของ water rides (minWaterEnd)
    int minWaterEnd = INT_MAX;
    for (int i = 0; i < m; i++) {
        int finish = waterStartTime[i] + waterDuration[i];
        if (finish < minWaterEnd) {
            minWaterEnd = finish;
        }
    }
    
    int ans = INT_MAX;
    
    // กรณีที่ 1: เล่น Land ก่อน แล้วตามด้วย Water
    for (int i = 0; i < m; i++) {
        if (waterStartTime[i] < minLandEnd) {
            // water ride เปิดก่อนที่ land จะจบ → เริ่ม water ได้ทันทีที่ land จบ
            int finish = minLandEnd + waterDuration[i];
            if (finish < ans) ans = finish;
        } else {
            // water ride เปิดหลังจาก land จบ → ต้องรอให้ water เปิด
            int finish = waterStartTime[i] + waterDuration[i];
            if (finish < ans) ans = finish;
        }
    }
    
    // กรณีที่ 2: เล่น Water ก่อน แล้วตามด้วย Land
    for (int i = 0; i < n; i++) {
        if (landStartTime[i] < minWaterEnd) {
            // land ride เปิดก่อนที่ water จะจบ → เริ่ม land ได้ทันทีที่ water จบ
            int finish = minWaterEnd + landDuration[i];
            if (finish < ans) ans = finish;
        } else {
            // land ride เปิดหลังจาก water จบ → ต้องรอให้ land เปิด
            int finish = landStartTime[i] + landDuration[i];
            if (finish < ans) ans = finish;
        }
    }
    
    return ans;
}