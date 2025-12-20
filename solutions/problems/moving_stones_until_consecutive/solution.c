/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sortThree(int* arr) {
    // Simple bubble sort for 3 elements
    if (arr[0] > arr[1]) {
        int temp = arr[0]; arr[0] = arr[1]; arr[1] = temp;
    }
    if (arr[1] > arr[2]) {
        int temp = arr[1]; arr[1] = arr[2]; arr[2] = temp;
    }
    if (arr[0] > arr[1]) {
        int temp = arr[0]; arr[0] = arr[1]; arr[1] = temp;
    }
}

int* numMovesStones(int a, int b, int c, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // Sort the positions
    int positions[3] = {a, b, c};
    sortThree(positions);
    
    int x = positions[0];
    int y = positions[1];
    int z = positions[2];
    
    // Minimum moves
    if (z - x == 2) {  // Already consecutive
        result[0] = 0;
    } else if (y - x <= 2 || z - y <= 2) {  
        // Gap of 1 or 2 on either side
        result[0] = 1;
    } else {
        result[0] = 2;
    }
    
    // Maximum moves
    // Total empty slots between stones
    result[1] = (z - x - 2);
    
    return result;
}