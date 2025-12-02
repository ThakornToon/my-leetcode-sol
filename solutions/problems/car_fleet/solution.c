typedef struct {
    int position;
    double time;
} Car;

int compareCars(const void* a, const void* b) {
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;
    // เรียงจาก position สูงไปต่ำ
    return carB->position - carA->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    int n = positionSize;
    if (n == 0) return 0;
    
    // สร้าง array ของรถ
    Car* cars = (Car*)malloc(n * sizeof(Car));
    
    // คำนวณเวลา
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    
    // เรียงรถตามตำแหน่งจากสูงไปต่ำ
    qsort(cars, n, sizeof(Car), compareCars);
    
    int fleets = 1;  // รถคันแรกเป็น fleet แน่นอน
    double currentMaxTime = cars[0].time;
    
    for (int i = 1; i < n; i++) {
        if (cars[i].time > currentMaxTime) {
            fleets++;
            currentMaxTime = cars[i].time;
        }
        // ถ้า time <= currentMaxTime → รวม fleet เดียวกัน
    }
    
    free(cars);
    return fleets;
}