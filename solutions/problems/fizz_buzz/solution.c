/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n; 
    char** answer; 
    int i = 1; 
    answer = (char**)malloc(sizeof(char*) * n); 
    while (i <= n) {
        if (i % 15 == 0) {
            answer[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            answer[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            answer[i - 1] = strdup("Buzz");
        } else {
            char str[5];
            sprintf(str, "%d", i);
            answer[i - 1] = strdup(str);
        }
        i++;
    }
    return (answer);
}