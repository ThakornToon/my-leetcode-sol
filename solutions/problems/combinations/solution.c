/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for(int i = 1; i <= k; i++){
        total = total * (n - k + i) / i;
    }
    int** res = (int**)malloc(sizeof(int*) * total);
    int* sub = (int*)malloc(sizeof(int) * (k + 1));  
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    *returnSize = 0;
    for (int i = 1; i <= k; i++) {
        sub[i] = i;
    }
    int count = k;

    /*
    for example
    12345
    _ _ _ -> 123 -> 124 -> 125 -> (120) -> (130) -> 134 ..... 
i:0 1 2 3
    */

    while (true) {
        if (sub[1] == 0) {
            break;
        }
        if (count >= k) {
            res[*returnSize] = (int*)malloc(sizeof(int) * k);
            memcpy(res[*returnSize], &sub[1], sizeof(int) * k);
            (*returnColumnSizes)[*returnSize] = k;
            (*returnSize)++;
            if (sub[count] >= n - k + count) {
                sub[count] = 0;
            } //145->140
            count--; //124->12(4)
            continue;
        }

        if (sub[count+1] == 0 && sub[count] < n - k + count) { //100->230->234
            sub[count]++;
            for (int i = count+1; i<=k; i++) {
                sub[i] = sub[i-1] + 1;
                count++;
            }
        }
        else if (sub[count+1] == 0 && sub[count] >= n - k + count) { //140->100
            sub[count] = 0;
            count--;
        }
        else {//12(4)->125
            count++;
            sub[count]++;
        }

    } 
    free(sub);
    return res;
}