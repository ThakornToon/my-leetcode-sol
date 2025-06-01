int candy(int* ratings, int ratingsSize) {
    int sum = ratingsSize; // เริ่มมาได้คนละหนึ่ง
    int i = 1;
    while (i < ratingsSize) {
        if (ratings[i] == ratings[i - 1]) { // 1 3 3 3 2 จะได้ลูกอมเป็น 1 2 1 2 1
            i++;
            continue;
        }

        int c_increase = 0;
        while (i < ratingsSize && ratings[i] > ratings[i - 1]) { // ลำดับเพิ่ม 1 3 4 5 ต้องให้ลูกอม 1 2 3 4
            c_increase++;
            sum += c_increase;
            i++;
        }

        int c_decrease = 0;
        while (i < ratingsSize && ratings[i] < ratings[i - 1]) { // ลำดับลด 5 3 2 สมมติคนแรกมีลูกอม 4 จะดูว่ามีน้อยกว่ากี่ตัว กรณีนี้มีสองก็จะได้ลูกอม 2 1
            c_decrease++;
            sum += c_decrease;
            i++;
        } // สังเกตุว่าที่บวกไปจะเรียงลูกอมเป็น 3 2 1 เราต้องเอาไปเทียบกับกรณีที่มากขึ้นอีกที

    if (c_increase > c_decrease) {
        sum -= c_decrease;
    }
    else {
        sum -= c_increase;
    } 
    // จะได้ลำดับ 1 3 4 5 3 2 ได้ลูกอม 1 2 3 4 2 1 เพราะตรงจุดเปลี่ยนจะเกิดการซ้อนกันต้องลบกรณีที่ได้น้อยออก
    }
    return sum;
}