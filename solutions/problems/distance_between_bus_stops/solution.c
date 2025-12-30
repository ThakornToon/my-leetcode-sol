

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    // คำนวณระยะทางตามเข็มนาฬิกา
    int clockwise = 0;
    for (int i = start; i % distanceSize != destination; i++) {
        clockwise += distance[i % distanceSize];
    }
    
    // คำนวณระยะทางทวนเข็มนาฬิกา
    int total = 0;
    for (int i = 0; i < distanceSize; i++) {
        total += distance[i];
    }
    int counterclockwise = total - clockwise;
    
    // คืนค่าที่น้อยกว่า
    return clockwise < counterclockwise ? clockwise : counterclockwise;
}