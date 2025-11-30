bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    if (rec1[0] >= rec2[2] ||  // rec1 อยู่ขวาสุดของ rec2
        rec1[2] <= rec2[0] ||  // rec1 อยู่ซ้ายสุดของ rec2  
        rec1[1] >= rec2[3] ||  // rec1 อยู่บนสุดของ rec2
        rec1[3] <= rec2[1]) {  // rec1 อยู่ล่างสุดของ rec2
        return false;
    }
    return true;
}