int numTeams(int* rating, int ratingSize) {
    int count = 0;
    
    for (int j = 0; j < ratingSize; j++) {
        int leftLess = 0, leftGreater = 0;
        int rightLess = 0, rightGreater = 0;
        
        // นับทางซ้ายของ j
        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) leftLess++;
            else if (rating[i] > rating[j]) leftGreater++;
        }
        
        // นับทางขวาของ j
        for (int k = j + 1; k < ratingSize; k++) {
            if (rating[k] < rating[j]) rightLess++;
            else if (rating[k] > rating[j]) rightGreater++;
        }
        
        // ทีมเพิ่มขึ้น: เลือก i ที่น้อยกว่า และ k ที่มากกว่า
        count += leftLess * rightGreater;
        
        // ทีมลดลง: เลือก i ที่มากกว่า และ k ที่น้อยกว่า
        count += leftGreater * rightLess;
    }
    
    return count;
}