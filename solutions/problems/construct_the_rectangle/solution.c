/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Start from the square root and work downwards
    int width = (int)sqrt(area);
    while (area % width != 0) {
        width--;
    }
    
    result[0] = area / width;  // length
    result[1] = width;         // width
    
    return result;
}