class Solution {
public:
    int strongPasswordChecker(string password) {
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDig = false;
        int charLen = password.length();
        
        for (char c : password) {
            if (c >= 'a' && c <= 'z') {
                hasLower = true;
            } else if (c >= 'A' && c <= 'Z') {
                hasUpper = true;
            } else if (c >= '0' && c <= '9') {
                hasDig = true;
            }
        }

        int missingTypes = 3 - (hasLower + hasUpper + hasDig);
        vector<int> repeats;
        
        int i = 0;
        while (i < charLen) {
            int j = i;
            while (j < charLen && password[j] == password[i]) {
                j++;
            }
            if (j - i >= 3) {
                repeats.push_back(j - i);
            }
            i = j;
        }

        if (charLen < 6) {
            return max(6 - charLen, missingTypes);
        } 
        else if (charLen <= 20) {
            int replace = 0;
            for (int len : repeats) {
                replace += len / 3;
            }
            return max(replace, missingTypes);
        } else {
            int overLen = charLen - 20;
            int deleteCount = overLen;
            
            // First pass: delete 1 from sequences with len % 3 == 0
            for (int k = 0; k < repeats.size() && overLen > 0; k++) {
                int len = repeats[k];
                if (len % 3 == 0) {
                    repeats[k] -= 1;
                    overLen -= 1;
                }
            }
            
            // Second pass: delete 2 from sequences with len % 3 == 1
            for (int k = 0; k < repeats.size() && overLen > 0; k++) {
                int len = repeats[k];
                if (len % 3 == 1 && overLen >= 2) {
                    repeats[k] -= 2;
                    overLen -= 2;
                }
            }
            
            // Third pass: delete 3 from other sequences
            for (int k = 0; k < repeats.size() && overLen > 0; k++) {
                while (repeats[k] >= 3 && overLen >= 3) {
                    repeats[k] -= 3;
                    overLen -= 3;
                }
            }
            
            // Calculate remaining replacements needed
            int replace = 0;
            for (int len : repeats) {
                if (len >= 3) {
                    replace += len / 3;
                }
            }
            
            return deleteCount + max(replace, missingTypes);
        }
    }
};