class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // Parse first complex number
        int plusPos1 = num1.find('+');
        int a = stoi(num1.substr(0, plusPos1));
        int b = stoi(num1.substr(plusPos1 + 1, num1.length() - plusPos1 - 2));
        
        // Parse second complex number
        int plusPos2 = num2.find('+');
        int c = stoi(num2.substr(0, plusPos2));
        int d = stoi(num2.substr(plusPos2 + 1, num2.length() - plusPos2 - 2));
        
        // Calculate real and imaginary parts
        int real = a * c - b * d;
        int imag = a * d + b * c;
        
        return to_string(real) + "+" + to_string(imag) + "i";

    }
};