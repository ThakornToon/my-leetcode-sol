class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        
        // ทำให้ start <= destination
        if (start > destination) {
            swap(start, destination);
        }
        
        // คำนวณระยะทางตามเข็มนาฬิกา (จาก start ไป destination)
        int clockwise = 0;
        for (int i = start; i < destination; i++) {
            clockwise += distance[i];
        }
        
        // คำนวณระยะทางทวนเข็มนาฬิกา (จาก destination ไป start ผ่านอีกทาง)
        int total = 0;
        for (int d : distance) {
            total += d;
        }
        int counterclockwise = total - clockwise;
        
        return min(clockwise, counterclockwise);
    }
};