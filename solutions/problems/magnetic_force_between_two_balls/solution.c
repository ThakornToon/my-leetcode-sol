int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// ตรวจสอบว่าสามารถวางลูกบอล m ลูกโดยห่างกันอย่างน้อย force ได้หรือไม่
int canPlace(int* position, int n, int m, int force) {
    int count = 1;  // วางลูกแรกที่ตำแหน่งแรก
    int lastPos = position[0];
    
    for (int i = 1; i < n; i++) {
        if (position[i] - lastPos >= force) {
            count++;
            lastPos = position[i];
            if (count >= m) {
                return 1;
            }
        }
    }
    
    return count >= m;
}

int maxDistance(int* position, int positionSize, int m) {
    // เรียงลำดับตำแหน่ง
    qsort(position, positionSize, sizeof(int), compare);
    
    int left = 1;
    int right = (position[positionSize - 1] - position[0]) / (m - 1) + 1;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlace(position, positionSize, m, mid)) {
            result = mid;
            left = mid + 1;  // ลองหาค่าที่มากขึ้น
        } else {
            right = mid - 1;  // ลองหาค่าที่น้อยลง
        }
    }
    
    return result;
}