int arrayNesting(int* nums, int numsSize) {
    int *visited = (int *)calloc(numsSize, sizeof(int));
    int max_length = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (!visited[i]) {
            int start = nums[i], count = 0;
            do {
                start = nums[start];
                count++;
                visited[start] = 1;
            } while (start != nums[i]);
            
            if (count > max_length) {
                max_length = count;
            }
        }
    }
    
    free(visited);
    return max_length;
}