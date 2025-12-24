/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    int* answer = (int*)calloc(n, sizeof(int));
    *returnSize = n;
    
    // ใช้ difference array
    for (int i = 0; i < bookingsSize; i++) {
        int first = bookings[i][0] - 1;  // เปลี่ยนเป็น 0-based
        int last = bookings[i][1] - 1;
        int seats = bookings[i][2];
        
        answer[first] += seats;
        if (last + 1 < n) {
            answer[last + 1] -= seats;
        }
    }
    
    // คำนวณ prefix sum
    for (int i = 1; i < n; i++) {
        answer[i] += answer[i - 1];
    }
    
    return answer;
}