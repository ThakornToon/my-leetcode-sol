/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* result = (int*)malloc(pricesSize * sizeof(int));
    
    for (int i = 0; i < pricesSize; i++) {
        int discount = 0;
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                discount = prices[j];
                break;
            }
        }
        result[i] = prices[i] - discount;
    }
    
    return result;
}