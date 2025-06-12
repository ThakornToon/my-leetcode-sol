char* getHint(char* secret, char* guess) {
    int bulls = 0, cows = 0;

    int mp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < strlen(secret); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            mp[secret[i] - '0']++;
        }
    }

    for (int i = 0; i < strlen(guess); i++) {
        if (mp[guess[i] - '0'] > 0 && guess[i] != secret[i]) {
            cows++;
            mp[guess[i] - '0']--;
        }
    }
    static char ans[10];
    sprintf(ans, "%dA%dB", bulls, cows);
    return ans;
}