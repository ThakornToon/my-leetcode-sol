class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long den = denominator;
        
        if (num == 0) return "0";
        
        bool isNegative = (num < 0) ^ (den < 0);
        num = abs(num);
        den = abs(den);
        
        string result;
        if (isNegative) result += "-";
        
        result += to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) return result;
        
        result += ".";
        
        // ใช้ unordered_map แทน vector
        unordered_map<long long, int> pos;
        
        while (remainder != 0) {
            if (pos.find(remainder) != pos.end()) {
                result.insert(pos[remainder], "(");
                result += ")";
                break;
            }
            
            pos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};