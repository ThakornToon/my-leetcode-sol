/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void dfs(int** image, int imageSize, int* imageColSize, 
                 int sr, int sc, int newColor, int originalColor) {
    // Check boundaries
    if (sr < 0 || sr >= imageSize || sc < 0 || sc >= imageColSize[sr]) {
        return;
    }
    
    // Check if pixel should be filled
    if (image[sr][sc] != originalColor) {
        return;
    }
    
    // Change color
    image[sr][sc] = newColor;
    
    // Recursively fill adjacent pixels
    dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, originalColor); // down
    dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, originalColor); // up
    dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, originalColor); // right
    dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, originalColor); // left
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    if (image[sr][sc] == color) {
        return image;
    }
    
    int originalColor = image[sr][sc];
    dfs(image, imageSize, imageColSize, sr, sc, color, originalColor);
    return image;
}