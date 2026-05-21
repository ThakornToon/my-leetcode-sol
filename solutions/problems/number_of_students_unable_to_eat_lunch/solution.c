int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count0 = 0, count1 = 0;
    
    // นับจำนวนนักเรียนที่ต้องการแบบกลม(0) และสี่เหลี่ยม(1)
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) count0++;
        else count1++;
    }
    
    // วนแซนด์วิชทีละชิ้น
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count0 > 0) {
                count0--;
            } else {
                // ไม่มีนักเรียนที่ต้องการ 0 แล้ว คนที่เหลือที่กิน 1 จะมากินไม่ได้
                return count1;
            }
        } else { // sandwiches[i] == 1
            if (count1 > 0) {
                count1--;
            } else {
                return count0;
            }
        }
    }
    
    return 0;
}