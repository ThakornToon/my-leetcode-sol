/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int wordLen[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        wordLen[i] = strlen(words[i]);
    }
    char** ans = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    int idx = 0;
    while (idx < wordsSize) {
        int start = idx;
        int curr_line = 0; //count all space and character
        int sum_of_ch = 0; //count only character
        bool last_line = false;
        while (idx < wordsSize && curr_line + wordLen[idx] <= maxWidth) {
            curr_line += wordLen[idx] + 1;
            sum_of_ch += wordLen[idx];
            idx++;
            if (idx == wordsSize) {
                last_line = true;
            }
        }
        int extra;
        int space;
        curr_line = idx - start; //change this variable to store number of word instead
        if (last_line || curr_line == 1) {
            extra = 0;
            space = maxWidth - sum_of_ch;
        }
        else {
            extra = (maxWidth - sum_of_ch) % (curr_line - 1);
            space = (maxWidth - sum_of_ch) / (curr_line - 1);
        }

        ans[*returnSize] = (char*)malloc((maxWidth+1) * sizeof(char));
        ans[*returnSize][0] = '\0';
        if (last_line) {
            for (; start < idx; start++) {
                strcat(ans[*returnSize], words[start]);
                if (start == idx-1) {
                    break;
                }
                strcat(ans[*returnSize], " ");
            }
            while (strlen(ans[*returnSize]) < maxWidth) {
                strcat(ans[*returnSize], " ");
            }
        }
        else {
            for (; start < idx; start++) {
                strcat(ans[*returnSize], words[start]);
                if (start == idx-1 && curr_line != 1) {
                    break;
                }
                for (int i = 0; i < space; i++) {
                    strcat(ans[*returnSize], " ");
                }
                if (extra > 0) {
                    strcat(ans[*returnSize], " ");
                    extra--;
                }
            }
        }
        (*returnSize)++;
    }
    return ans;
}