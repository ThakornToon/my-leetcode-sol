class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size() - 1, l2 = num2.size() - 1;
        int carry = 0;
        string result = "";
        while (l1 >= 0 || l2 >= 0 || carry){
            int sum = carry;
            if (l1 >= 0) {
                sum += num1[l1--] - '0';
            }
            if (l2 >= 0) {
                sum += num2[l2--] - '0';
            }
            result += ((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};