/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isValid(char* s) {
    int balance = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

void backtrack(char* s, int start, int left_rem, int right_rem, char** result, int* returnSize) {
    if (left_rem == 0 && right_rem == 0) {
        if (isValid(s)) {
            result[*returnSize] = strdup(s);
            (*returnSize)++;
        }
        return;
    }

    for (int i = start; s[i]; i++) {
        if (i > start && s[i] == s[i-1]) continue; // skip duplicates
        if (s[i] == '(' && left_rem > 0) {
            char* new_str = (char*)malloc(strlen(s));
            strncpy(new_str, s, i);
            strcpy(new_str + i, s + i + 1);
            backtrack(new_str, i, left_rem - 1, right_rem, result, returnSize);
            free(new_str);
        }
        if (s[i] == ')' && right_rem > 0) {
            char* new_str = (char*)malloc(strlen(s));
            strncpy(new_str, s, i);
            strcpy(new_str + i, s + i + 1);
            backtrack(new_str, i, left_rem, right_rem - 1, result, returnSize);
            free(new_str);
        }
    }
}

char** removeInvalidParentheses(char* s, int* returnSize) {
    int left_rem = 0, right_rem = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            left_rem++;
        } else if (s[i] == ')') {
            if (left_rem > 0) left_rem--;
            else right_rem++;
        }
    }

    char** result = (char**)malloc(100 * sizeof(char*));
    *returnSize = 0;
    backtrack(s, 0, left_rem, right_rem, result, returnSize);
    return result;
}