int minCostToMoveChips(int* position, int positionSize) {
    int evenCount = 0;
    int oddCount = 0;
    
    for (int i = 0; i < positionSize; i++) {
        if (position[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    // คืนค่าที่น้อยกว่าของ evenCount และ oddCount
    return (evenCount < oddCount) ? evenCount : oddCount;
}