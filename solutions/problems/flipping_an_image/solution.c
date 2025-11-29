/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = malloc(imageSize * sizeof(int));
    
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
        
        int left = 0, right = imageColSize[i] - 1;
        while (left <= right) {
            // Swap and invert
            int temp = 1 - image[i][left];
            image[i][left] = 1 - image[i][right];
            image[i][right] = temp;
            
            left++;
            right--;
        }
    }
    
    return image;
}