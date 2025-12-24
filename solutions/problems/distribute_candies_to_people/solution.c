/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize) {
    int* result = (int*)calloc(num_people, sizeof(int));
    *returnSize = num_people;
    
    int i = 0;
    int give = 1;
    
    while (candies > 0) {
        int current_give = (give < candies) ? give : candies;
        result[i % num_people] += current_give;
        candies -= current_give;
        give++;
        i++;
    }
    
    return result;
}