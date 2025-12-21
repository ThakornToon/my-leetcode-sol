class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
        return "";
    }
    
    // หา GCD ของความยาว
    int len1 = str1.length();
    int len2 = str2.length();
    
    // Euclidean algorithm
    int a = len1, b = len2;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    // เอา prefix ยาว a จาก str1
    return str1.substr(0, a);
    }
};