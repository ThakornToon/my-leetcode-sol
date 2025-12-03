bool buddyStrings(char* s, char* goal) {
    int n = strlen(s);
    if (strlen(goal) != n) {
        return false;
    }
    int Shash[26] = {0};
    int Ghash[26] = {0};
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            diff += 1;
        }
        Shash[s[i] - 'a'] += 1;
        Ghash[goal[i] - 'a'] += 1;
    }

    int dup = 0;

    for (int i = 0; i < 26; i++) {
        if (Shash[i] == Ghash[i]) {
            if (Shash[i] >= 2) {
                dup = 1;
            }
        } else {
            return false;
        }
    }

    if (diff > 2 || (diff == 0 && dup == 0)) {
        return false;
    }

    return true;
}