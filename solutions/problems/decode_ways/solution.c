int numDecodings(char* s) {
    if (s[0] == '0') {
        return 0;
    }
    int di = s[0] - '0';
    int count_one = 0;
    int prev_count_one = 1;
    int count_two = 0;
    int prev_count_two = 0;
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == '0') {
            count_one = 0;
        }
        else if (s[i] > '0') {
            count_one = prev_count_one + prev_count_two;
        }

        di = (di % 10 * 10) + s[i] - '0';
        if (di > 0 && di <= 26) {
            count_two = prev_count_one;
        }
        else {
            count_two = 0;
        }

        if (count_one == 0 && count_two == 0) {
            return 0;
        }
        prev_count_one = count_one;
        prev_count_two = count_two;
    }
    return prev_count_one + prev_count_two;
}

/*
A valid decode result belongs to one of the following two categories:

Category 1: ending with a valid one-digit (for example: [........, 9] or [.........., 2])
Category 2: ending with a valid two-digit (for example: [........, 12] or [........, 20] or [........, 16] )

For a certain input string, the total count of valid results = count of Category 1 results + count of Category 2 results.

Applying the principle of dynamic programing, when we do a loop on the input string, while we are at a certain character, we try to get new valid decode results by adding this new character onto the valid results ending at the previous character.

Because each valid decode result is in either Category 1 or 2, we have 4 cases:

Category 1 to Category 1 (for example: [........, 9] --add X--> [........, 9, X])
Category 1 to Category 2 (for example: [........, 2] --add X--> [........, 2X])
Category 2 to Category 1 (for example: [........, 20] --add X--> [........, 20, X])
Category 2 to Category 2 is Impossible. (for example: [........, 21] --cannot change into-- > [........, 2, 1X])

We keep track of the counts of Category 1 and Category 2 results ending at each character, using count1 as the count of Category 1 and count2 as count of Categoty 2.

Since both Category 1 and 2 can be changed into Category 1, therefore,

count1 = previous count1 + previous count2

If the character is '0', then the equation above is not valid. In that case, because neither [………., X, 0] or [……., XX, 0] is valid, there is no valid solution ending with one-digit '0'. As a result, we set count1 to 0.

Only Category 1 can be changed into Category 2, therefore,

count2 = previous count1

This equation is not valid if the new character cannot form a valid two-digit with the previous character. For example, [........, 9] --cannot be --> [........, 9X]. Another example, [........, 2] –cannot be --> [........, 29]. If that is the case, we set count2 to 0.
*/