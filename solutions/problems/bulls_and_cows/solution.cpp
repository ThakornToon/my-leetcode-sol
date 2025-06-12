class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        unordered_map<char, int> mp;

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                mp[secret[i]]++;
            }
        }

        for (int i = 0; i < guess.length(); i++) {
            if (mp[guess[i]] > 0 && guess[i] != secret[i]) {
                cows++;
                mp[guess[i]]--;
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};